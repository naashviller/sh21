#!/bin/bash

if [ -n "$1" ]
then
    echo "Указано большее количество параметров, укажите 0 параметров."
else
    chmod +x ./script02.sh
    ./script02.sh
    read -p "Хотите создать файл содержащий информацию, которая была выведена на экран: Y/N" tmp
    if [[ $tmp =~ ^[Y,y]+$ ]]
    then
        ./script02.sh > $(date +%d_%m_%Y_%k_%M_%S).status
    fi
fi
