from pathlib import Path
import json

CUR_DIR = Path.cwd()
CONFIG_FILE = ''

while True:
    if Path(CUR_DIR / 'judger').exists():
        CONFIG_FILE = CUR_DIR / 'judger/config/language_config.json'
        break
    CUR_DIR = CUR_DIR.parent

class Language:
    def __init__(self,lang_name,task_dir,judge_dir):
        self.lang = lang_name
        self.TASK_DIR = task_dir
        self.JUDGE_DIR = judge_dir
        self.lang_dict_config = {}
        
    # task_name is just name without extension.
    def compile(self,task_name):
        pass
    
    def run(self,task_name):
        pass
    
    def readConfig(self) -> dict:
        json_dict = {}
        with open(CONFIG_FILE,'r') as json_file:
            json_dict = json.load(json_file)
        return json_dict[self.lang]
    
    def execute(self,task_name) -> int:
        self.lang_dict_config = self.readConfig()
        return self.compile(task_name)
