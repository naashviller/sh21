#!/bin/bash

START_TIME=$(date +%s)
if [ -n "$2" ]
then
    echo "Указано большее параметров, чем необходимо, укажите 1 параметр."
else
    if [ -n "$1" ]
    then
        if [[ $1 =~ ^(.+[/])?$ ]]
        then
            chmod +x ./script05.sh
            ./script05.sh $1
        else
            echo "Параметр неправильного формата, строка должна заканчиваться символом '/'."
        fi
    else
        echo "Указаны не все параметры , укажите 1 параметр."
    fi
fi

END_TIME=$(date +%s)
difference=$(( $END_TIME - $START_TIME ))
echo "Script execution time (in seconds) = $difference"
