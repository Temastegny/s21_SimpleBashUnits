#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

declare -a tests=(
"s parser.c VAR"
# "for parser.c reader.c Makefile VAR"
"for parser.c VAR"
# " -e ^int parser.c reader.c Makefile VAR"
"-e for  parser.c VAR"
"-e regex  parser.c VAR "
# "-e while  parser.c Makefile VAR "
)

declare -a extra=(
"-n for test_1_grep.txt test_2_grep.txt"
"-n for test_1_grep.txt"
"-n -e ^\} test_1_grep.txt"
"-c -e /\/ test_1_grep.txt"
"-e ^int test_1_grep.txt"
"-e"
"-n -e out test_5_grep.txt"
"-in int test_5_grep.txt"
"-v test_1_grep.txt -e ank"
"-l for test_1_grep.txt test_2_grep.txt"
"-e =  test_5_grep.txt"
# "-e ing  test_6_grep.txt"
"-l for no_file.txt test_2_grep.txt"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_grep $t > test_s21_grep.log
    grep $t > test_sys_grep.log
    DIFF_RES="$(diff -s test_s21_grep.log test_sys_grep.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_grep.log and test_sys_grep.log are identical" ]
    then
      (( SUCCESS++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m grep $t"
    else
      (( FAIL++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m grep $t"
    fi
    rm test_s21_grep.log test_sys_grep.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in v c l n i
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done



echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"