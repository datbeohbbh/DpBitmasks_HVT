#!usr/bin/bash

cd judger
read -p "did you configured the contest? y / n: " answer 

if [ $answer == "n" ];
then
    python3 config_judger.py
fi
