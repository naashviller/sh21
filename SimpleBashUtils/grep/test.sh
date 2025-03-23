#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0

flagss=(
    "i"
    "v"
    "c"
    "l"
    "n"
    "h"
    "s"
    "o"
)

function comp {
    ./s21_grep $flag $pattern $name $name1 > s21_grep.txt; grep $flag $pattern $name $name1 > grep.txt
    if diff s21_grep.txt grep.txt
    then
        echo "$COUNTER : SUCCESFULL"
        let "SUCCESS++"
    else
        echo "$COUNTER : FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"
}

function flags {
    echo "-----------------------"
    echo "1 PARAMETER"
    echo "-----------------------"
    for par in "${flagss[@]}"
    do 
        flag="-$par"
        comp
    done
    echo "-----------------------"
    echo "2 PARAMETER"
    echo "-----------------------"
    for par1 in "${flagss[@]}"
    do
        for par2 in "${flagss[@]}"
        do
            if [ $par1 != $par2 ]
            then
                flag="-$par1$par2"
                comp
            fi
        done
    done
    echo "-----------------------"
    echo "3 PARAMETERS"
    echo "-----------------------"
    for par1 in "${flagss[@]}"
    do
        for par2 in "${flagss[@]}"
        do
            for par3 in "${flagss[@]}"
            do
                if [ $par1 != $par2 ] && [ $par2 != $par3 ] && [ $par1 != $par3 ]
                then
                    flag="-$par1$par2$par3"
                    comp
                fi
            done
        done
    done
    echo "-----------------------"
    echo "4 PARAMETERS"
    echo "-----------------------"
    for par1 in "${flagss[@]}"
    do
        for par2 in "${flagss[@]}"
        do
            for par3 in "${flagss[@]}"
            do
                for par4 in "${flagss[@]}"
                do
                    if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                    && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                    && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                    then
                    flag="-$par1$par2$par3$par4"
                    comp
                    fi
                done
            done
        done
    done
}

function names {
    name=test.txt
    name1=""
        flags
        echo "----------"
    name=test.txt
    name1=test1.txt
        flags
        echo "----------"
    name=test.txt
    name1=nonexist.txt
        flags
        echo "----------"
        
}


for pattern in use ReGeX
do
    names
done



echo "----------"
echo "----------"

./s21_grep > s21_grep.txt; grep > grep.txt
if diff s21_grep.txt grep.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"

./s21_grep -e [.*] test.txt > s21_grep.txt; grep -e [.*] test.txt > grep.txt
if diff s21_grep.txt grep.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"
    
./s21_grep -e dressed -e usually test.txt > s21_grep.txt; grep -e dressed -e usually test.txt > grep.txt
if diff s21_grep.txt grep.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"
    
./s21_grep -f file_test.txt test.txt > s21_grep.txt; grep -f file_test.txt test.txt > grep.txt
if diff s21_grep.txt grep.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"

./s21_grep -f file_test.txt -e [.*] test.txt > s21_grep.txt; grep -f file_test.txt -e [.*] test.txt > grep.txt
if diff s21_grep.txt grep.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"

echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"