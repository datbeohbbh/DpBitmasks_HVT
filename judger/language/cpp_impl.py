from language.language_execute_base import Language
import os
from pathlib import Path
import sys

class CppImpl(Language):

    def __init__(self,task_dir,judger_dir):
        super().__init__('c++',task_dir,judger_dir)
        
    def compile(self,task_name,*args):
        compile_dict = self.lang_dict_config['compile']
        compile_cmd = compile_dict['command'] + compile_dict['version'] 
        compile_flag = " ".join(compile_dict['flag'])
        compile_out = " ".join([self.TASK_DIR + '/' + task_name + '.cpp',compile_dict['out'],self.JUDGE_DIR + '/' + task_name])
        command = " ".join([compile_cmd,compile_flag,compile_out," ".join(list(args))])
        #print('--> compile with command \n {0}'.format(command))
        os.system(command)
        
    def run(self,task_name,*args):
        #print(len(args),list(args[0]))
        run_list = self.lang_dict_config['run']
        run_cmd = " ".join(run_list)
        command = " ".join(['cd',self.JUDGE_DIR,'&&',run_cmd + task_name,' '.join(list(args[0]))])
        #print('--> run with command \n {0}'.format(command))
        os.system(command)
        

#CUR_DIR = Path.cwd()
#PR_DIR = CUR_DIR.parent
#x = CppImpl(str(CUR_DIR),str(PR_DIR))
#
#x.execute("zbx")
##
#x.run("zbx","<",str(PR_DIR) + '/' + "test.inp")

