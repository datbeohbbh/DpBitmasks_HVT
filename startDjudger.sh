#!/usr/bin/env bash

cd judger && python3 Djudger.py 

ret=$?

if [ $ret -eq 0 ];
then
    exit 0
else
    exit 1
fi
