#!/bin/bash

function search {
    for ((i = 1;; i++))
    do
        tmp=$(sudo ls -l $1 | grep "^-" | awk '(NR == '$i'){print $9}')
        if [ -z $tmp ]
        then
	    echo "1" >> file_name.txt
            break
        else
            echo "$1$tmp" >> file_name.txt
        fi
    done
}

function utils_file {
    for ((i = 1; i <= 10; i++))
    do
        column_3=$(sudo ls -lSh $1 | grep "^-" | awk '(NR == '$i') {print $9}' | sed  's|.*\.||')
        column_2=$(sudo ls -lSh $1 | grep "^-" | awk '(NR == '$i') {print $5}')
        column_1=$(sudo ls -lSh $1 | grep "^-" | awk '(NR == '$i') {print $9}')
        if [ -z "$column_1" ]
        then
            continue
        else
            echo "$i - $1$column_1, $column_2, $column_3"
        fi
    done
}

function utils_file_exe {
    for ((i = 1; i <= 10; i++))
    do
        column_2=$(sudo ls -lSha $1 | grep "^-" | grep "^...x" | awk '(NR == '$i'){print $5}')
        column_1=$(sudo ls -lSha $1 | grep "^-" | grep "^...x" | awk '(NR == '$i'){print $9}')
        if [ -z "$column_1" ]
        then
            continue
        else
            column_3=$(md5sum $1$column_1 | awk '{print $1}')
            echo "$i - $1$column_1, $column_2, $column_3"
        fi
    done
}

function utils_directory {
    for ((i = 1; i <= 5; i++))
    do
        column_2=$(sudo du -h $1 | sort -hr | awk '(NR == '$i') {print $2}')#r - reverse, h-от мин до макс, печ путь
        column_1=$(sudo du -h $1 | sort -hr | awk '(NR == '$i') {print $1}')#печ вес
        if [ -z "$column_1" ]
        then
            continue
        else
            echo "$i - $column_2, $column_1"
        fi
    done
}