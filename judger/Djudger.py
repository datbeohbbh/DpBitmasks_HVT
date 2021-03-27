import os
from pathlib import Path
import subprocess
import re
import sys
import multiprocessing
import time
import threading
import json
import math

from language.language_execute_base import Language
from language.cpp_impl import CppImpl
from language.python_impl import PythonImpl
from language.java_impl import JavaImpl
from test_check_lib import test_match

# set class suit with extension
lang_process = {
    '.cpp' : CppImpl,
    '.java' : JavaImpl,
    '.py' : PythonImpl,
}

CUR_DIR = Path.cwd()
UP_DIR = CUR_DIR.parent

def readTestDirName() -> dict:
    with open('config/judger_config.json') as task_config:
        return json.load(task_config)['test_dir']
    

def readTaskConfig() -> dict:
    with open('config/judger_config.json') as task_config:
        return json.load(task_config)['task']


def readCompetitorTask() -> list:
    competitor_task_path = []
    with open('config/language_config.json') as language_config:
        extension_dict = json.load(language_config)['extension']
        for extension,lang_name in extension_dict.items():
            competitor_task_path += [task for task in Path(UP_DIR / 'competitor').glob('**/*' + extension)]
    return competitor_task_path


def getLangProcess(extension,task_dir,judger_dir):
    return lang_process[extension](task_dir,judger_dir)

### get test directory path and task configuration

TEST_DIR = UP_DIR / readTestDirName()
task_config = readTaskConfig()

# read path to competitor's task

competitor_task_path = readCompetitorTask()

# creat judger zone directory

Path('judger_zone').mkdir(exist_ok = True)


# Start Djudger 
# standard input
# standart output


def runTest(process,task_name,*args):
    process.run(task_name,args)
    
def startMultiprocessing(process,task_name,time_limit,args):
    cur_thread = multiprocessing.Process(target = runTest,name = 'runTest',
                                         args = (process,
                                                 task_name,
                                                 args,))
    cur_thread.start()
    cur_thread.join(time_limit)
    is_alive = cur_thread.is_alive()
    if is_alive:
        cur_thread.terminate()
        cur_thread.join()
        return True
    else:
        return False


def testCompare(author_ans,competitor_ans) -> bool:
    return test_match.testCompare(author_ans,competitor_ans)

def doChecker(checker_process,checker_name,inp,out,ans) -> int:
    return test_match.doChecker(checker_process,checker_name,inp,out,ans)

def Djudger():
    Full = True
    for task_path in competitor_task_path:
        print("Start testing task {0}\n".format(task_path.name))
        extension = task_path.suffix
        task_name = task_path.stem
        if extension in lang_process == False:
            print("{0} extension have not been supported yet\n".format(extension))
            Full = False
        else :
            score = 0.0
            
            process = getLangProcess(extension,str(task_path.parent),str(CUR_DIR / 'judger_zone'))
            signal = process.execute(task_name)
            
            if signal != 0:
                print("Fail to compile task {0}\n".format(task_name))
                continue
            
            task = task_config[task_name]
            time_limit = task['time_limit']
            test_count = task['test_count']

            checker_process = None
            checker_name = ''
            checker_extension = ''
            
            if task['checker']:
                checker_name,checker_extension = task['checker'].split('.')
                checker_process = getLangProcess(checker_extension,str(TEST_DIR / task_name),str(CUR_DIR / 'judger_zone'))
                checker_process.execute(checker_name)
            else :
                del checker_process
                del checker_name
                del checker_extension
            
            for test_id in range(test_count):
                TEST_PATH = TEST_DIR / task_name / ('test' + str(test_id))
                print("Running on test {0}".format(test_id))

                is_alive = startMultiprocessing(process,
                                                task_name,
                                                time_limit,
                                                ['<',str(TEST_PATH) + '/' + task_name + '.inp', 
                                                '>',str(CUR_DIR / 'judger_zone' / 'test.ans')])
                
                if is_alive:
                    print("test {0}: TLE\n".format(test_id))
                else :
                    is_match = False
                    if task['checker']:
                        is_match = doChecker(checker_process,
                                             checker_name,
                                             str(TEST_PATH) + '/' + task_name + '.inp',
                                             str(TEST_PATH) + '/' + task_name + '.out',
                                             str(CUR_DIR / 'judger_zone' / 'test.ans'),)
                    else:
                        is_match = testCompare(str(TEST_PATH) + '/' + task_name + '.out'
                                              ,str(CUR_DIR / 'judger_zone' / 'test.ans'))
                    if is_match:
                        print("test {0}: OK\n".format(test_id))
                        score += 100 / test_count
                    else:
                        print("test {0}: WA\n".format(test_id))
        if math.ceil(score) == 100:
            print("perfect result: 100/100\n")
        else:
            print("partial result: {0}/100\n".format(math.ceil(score)))
            Full = False
        print('\n')
        
    for f in Path(CUR_DIR / 'judger_zone').iterdir():
        Path(f).unlink()
    Path(CUR_DIR / 'judger_zone').rmdir()
    
    if Full == False:
        return 1
    else:
        return 0
        
if __name__ == '__main__':
    signal = Djudger()
    sys.exit(signal)