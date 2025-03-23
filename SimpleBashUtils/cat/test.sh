#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0

flagss=(
    "b"
    "e"
    "n"
    "s"
    "t"
    "v"
)

function comp {
    ./s21_cat $flag $name $name1 > s21_cat.txt; cat $flag $name $name1 > cat.txt
    if diff s21_cat.txt cat.txt
    then
        echo "$COUNTER : SUCCESS"
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

name=test.txt
name1=""
flags
echo "----------"
name=test.txt
name1=test.txt
flags
echo "----------"
name=test.txt
name1=nonexist.txt
flags
echo "----------"

echo "----------"
echo "----------"

./s21_cat --number-nonblank test.txt > s21_cat.txt; cat -b test.txt > cat.txt
    if diff s21_cat.txt cat.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"
    
    
./s21_cat --number test.txt > s21_cat.txt; cat -n test.txt > cat.txt
    if diff s21_cat.txt cat.txt
    then
        echo "SUCCESFULL"
        let "SUCCESS++"
    else
        echo "FAIL"
        let "FAIL++"
    fi
    let "COUNTER++"

./s21_cat --squeeze-blank test.txt > s21_cat.txt; cat -s test.txt > cat.txt
    if diff s21_cat.txt cat.txt
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


