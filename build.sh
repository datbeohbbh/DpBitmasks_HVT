#!usr/bin/bash

DIR=$PWD

NEED=2

if [ $# -ne $NEED ];
then
    echo "$0 need to be passed $NEED arguments"
    exit 1
fi

echo "Build $1"

echo 

PRJ=$1

NUMBER_TEST=$2

TEST_DIR=$DIR/$PRJ


#####################################################################################################################################

read -p "Enter task: " TASK

for task in $TASK;
do
    echo "Building tests of task $task"
    TO_TASK_DIR=$TEST_DIR/$task
    LIST=$(ls $TO_TASK_DIR | grep -E "test[[:digit:]]+")
    for test_dir in $LIST;
    do
        echo "--> Removing $test_dir"
        rm -r $TO_TASK_DIR/$test_dir 2> /dev/null
    done;
    
    solution=$(ls $TO_TASK_DIR | grep -E ".+_solution\.cpp")
    gentest=$(ls $TO_TASK_DIR | grep -E ".+_gentest\.cpp")
    
    if [ ! "$solution" ] || [ ! "$gentest" ]; 
    then
        echo "--> Build failed"
    else
        echo "--> Compiling $solution"
        g++-10 -Wall -Wextra -Wshadow -Wconversion -std=c++2a -g -O2 $TO_TASK_DIR/$solution -o $TO_TASK_DIR/"$task"_solution
        
        echo "--> Compiling $gentest"
        g++-10 -Wall -Wextra -Wshadow -Wconversion -std=c++2a -g -O2 $TO_TASK_DIR/$gentest -o $TO_TASK_DIR/"$task"_gentest
        
        sol=$TO_TASK_DIR/"$task"_solution
        gen=$TO_TASK_DIR/"$task"_gentest
        
        for (( i=0; i < $NUMBER_TEST; i++));
        do
            mkdir -p $TO_TASK_DIR/test$i
            TO_TEST_DIR=$TO_TASK_DIR/test$i
            touch $TO_TEST_DIR/$task.inp $TO_TEST_DIR/$task.out
            echo "--> Creating test $i"
            $gen > $TO_TEST_DIR/$task.inp
            $sol < $TO_TEST_DIR/$task.inp > $TO_TEST_DIR/$task.out
        done;
        echo 
        echo "Build successfully test of task $task"
        
        rm $TO_TASK_DIR/"$task"_solution
        rm $TO_TASK_DIR/"$task"_gentest
    fi
    echo
    echo
done;

exit 0
