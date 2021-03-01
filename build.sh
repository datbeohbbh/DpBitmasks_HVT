#!usr/bin/bash

DIR=$PWD
TEST_DIR=$DIR/tests

# You can edit from here
TASK_FROM=A
TASK_TO=E
NUMBER_TEST=30
# to here.

for task in $(eval echo {$TASK_FROM..$TASK_TO});
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
    #echo $solution $gentest
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
        echo $sol $gen
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
    fi
    echo
    echo
done;

