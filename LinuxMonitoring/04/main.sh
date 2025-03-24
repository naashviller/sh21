#!/bin/bash

chmod +x ./script_color.sh
source ./script_color.sh
search
default_color

if [ -n "$1" ]
then
    echo "Указано больше параметров, чем необходимо, укажите 0 параметров."
else
    if [[ $clr_1 =~ ^[1-6]?$ ]] && [[ $clr_2 =~ ^[1-6]?$ ]] && [[ $clr_3 =~ ^[1-6]?$ ]] && [[ $clr_4 =~ ^[1-6]?$ ]]
    then
        if [ $clr_1 -ne $clr_2 ] && [ $clr_3 -ne $clr_4 ]
        then
            chmod +x ./script04.sh
            ./script04.sh $clr_1 $clr_2 $clr_3 $clr_4
        else
            echo "Цвета шрифта и фона одного столбца не должны совпадать. Измените конфигурационный файл."
        fi
    else
        echo "Параметр неправильного формата. Измените конфигурационный файл."
    fi
fi
