import os
import json
from pathlib import Path

CUR_DIR = Path.cwd()
UP_DIR = CUR_DIR.parent

judger_config_dict = {}

def enterTestDirectory() -> str:
    test_dir = ''
    while True: 
        print("Enter test directory ")
        test_dir = str(input())
        if Path(UP_DIR / test_dir).exists():
            break
        else :
            print("Folder not exists, try again!!",end = '\n')
    return test_dir

def enterTaskConfig() -> dict:
    print("Enter the number of tasks")
    ret_dict = {}
    num_task = int(input())
    for _ in range(num_task):
        task = ''
        while True:
            print("Enter task name")
            task = str(input())
            if task in ret_dict:
                print("task {0} has been configured, try again!!".format(task))
            else :
                break
        print("Start entering information of task {0}".format(task))
        task_dict = {}
        while True:
            print("--> Checker need? y / n")
            ask = str(input())
            if ask != 'y' and ask != 'n':
                print("--> Try again",end = '\n')
            elif ask == 'n':
                task_dict.update({'checker' : None})
                break
            else:
                print("--> Enter checker name")
                task_dict.update({'checker' : str(input())})
                break
        print("--> Enter time limit per test")
        task_dict.update({'time_limit' : int(input())})
        print("--> Enter the number of test for task {0}".format(task))
        task_dict.update({'test_count' : int(input())})
        ret_dict.update({task : task_dict})
        print("Task {0} was configured successfully.".format(task))
    return ret_dict

def createCompetitor():
    task_dict = judger_config_dict['task']
    Path(UP_DIR / 'competitor').mkdir(exist_ok = True)
    for task,task_info in task_dict.items():
        Path(UP_DIR / ('competitor' + '/' + task)).mkdir(exist_ok = True)

###                                                          ###
judger_config_dict.update({'test_dir' : enterTestDirectory()})
judger_config_dict.update({'task' : enterTaskConfig()})
createCompetitor()
###                                                          ### 

Path(CUR_DIR / 'config/judger_config.json').touch()
with open(Path(CUR_DIR / 'config/judger_config.json'),'w',encoding = 'utf8') as json_file:
    json.dump(judger_config_dict,json_file,indent = 6)
