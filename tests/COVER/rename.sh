#!/usr/bin/env bash

TEST=$(ls)
test_id=0

for test in $TEST;
do
    if [ $test != "COVER.CPP" ] && [ $test != "check.cpp" ] && [ $test != "rename.sh" ];
    then
        mv $test test$test_id
        test_id=$(($test_id+1))
    fi
done;
