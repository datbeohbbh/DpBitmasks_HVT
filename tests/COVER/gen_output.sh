#!/usr/bin/env bash

solution="COVER_solution"

for test in $(ls);
do
    if [ $test != "COVER_solution" ] && [ $test != "COVER_solution.cpp" ] && [ $test != "gen_output.sh" ] && [ $test != "rename.sh" ];
    then
        ./$solution < $test/"COVER.inp" > $test/"COVER.out"
    fi
done;
