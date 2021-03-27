from language.language_execute_base import Language
import os
from pathlib import Path
import sys

class PythonImpl(Language):

    def __init__(self,task_dir,judger_dir):
        super().__init__('python3',task_dir,judger_dir)
        
    def compile(self,task_name,*args):
        pass
        
    def run(self,task_name,*args):
        pass
        


