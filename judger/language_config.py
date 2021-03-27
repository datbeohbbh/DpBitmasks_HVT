import json
from pathlib import Path

CUR_DIR = Path.cwd()

LANGUAGE_CONFIG_FILENAME = "language_config.json"

language_config_dict = {
    "extension" : {
        ".cpp" : "c++",
        ".java" : "java",
        ".py" : "python3"
    },
    "c++" : {
        "compile" : {
            "command" : "g++",
            "version" : "",
            "flag" : ["-Wall", "-Wextra", "-Wshadow", "-Wconversion", "-Wfatal-errors", "-std=c++17" ,"-g", "-O2"],
            "out" : "-o"
        },
        "run" : [
            "./"
        ]
    },
    "java" : {
        "compile" : {
            "command" : "javac",
            "out" : "-d"
        },
        "run" : [
            "java"
        ]
    },
    "python3" : {
        "compile" : {
            "command" : "cp"
        },
        "run" : [
            "python3"
        ]
    }
}

with open(CUR_DIR / ('config/' + LANGUAGE_CONFIG_FILENAME),"w") as json_file:
    json.dump(language_config_dict,json_file,indent = 6)
