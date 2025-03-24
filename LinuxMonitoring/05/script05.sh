#!/bin/bash


chmod +x ./script_func.sh
source ./script_func.sh


search $1
#R - все файлы/катал/подкатал
echo "Total number of folders (including all nested ones) = $(sudo ls -lR $1 | grep "^d" | wc -l | awk '{print $1}')
TOP 5 folders of maximum size arranged in descending order (path and size):
$(utils_directory $1)
etc up to 5
Total number of files = $(sudo ls -l $1 | grep "^-" | wc -l | awk '{print $1}')
Number of:
Configuration files (with the .conf extension) = $(sudo ls -l $1 | grep "^-" | awk '{print $9}' | grep ".conf$" | wc -l | awk '{print $1}')
Text files = $(sudo file --mime-type -f file_name.txt | awk '{print $2}' | grep "^text" | wc -l | awk '{print $1}')
Executable files = $(sudo ls -l $1 | grep "^-" | awk '{print $1}' | grep "^...x" | wc -l | awk '{print $1}')
Log files (with the extension .log) = $(sudo ls -l $1 | grep "^-" | awk '{print $9}' | grep ".log$" | wc -l | awk '{print $1}')
Archive files = $(sudo file --mime-type -f file_name.txt | awk '{print $2}' | grep -E "(zip|tar|arj|rar|cab|lzh)$" | wc -l | awk '{print $1}')
Symbolic links = $(sudo find $1 -type l -name "*"| wc -l | awk '{print $1}')
TOP 10 files of maximum size arranged in descending order (path, size and type):
$(utils_file $1)
etc up to 10
TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)
$(utils_file_exe $1)
etc up to 10"

rm file_name.txt
