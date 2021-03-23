#!usr/bin/bash

cd judger
read -p "did you configured the contest? y / n: " answer 

if [ $answer == "n" ];
then
    python3 config_judger.py
fi

python3 Djudger.py 

ret=$?

if [ $ret -eq 0 ];
then
    exit 0
else
    exit 1
fi
