#!/bin/bash

folder_letters="$1"
file_letters="$2"
file_size_kb="$3"

ENG_WORD="^[a-zA-Z]+$"
DOT=".*\."
UNIT_MEASURE_KB="^kb$"

function checkSpace()
{
    space_available=$(df -h / | awk 'NR==2 {print $4}' | tr -d '[[:alpha:]]')
    limit=1
    if [[ $available -gt $limit ]]; then
        echo "Error: меньше 1 Гб места"
        exit 1
    fi
}

if [[ ! $folder_letters =~ $ENG_WORD ]]
then
	echo "Error: используйте английский буквы для названия папки"
	exit 1
fi

if [[ (${#folder_letters} -gt 7) || (${#folder_letters} -lt 1) ]]
then
	echo "Error: название папки от 1 до 7 символов"
    exit 1
fi

if [[ ! $file_letters =~ $DOT ]]
then
	echo "Error: используйте разделитель"
	exit 1
fi


FILE_NAME=${file_letters%.*} #имя
FILE_EXTENSION=${file_letters#*.} #расширение

if [[ (! $FILE_NAME =~ $ENG_WORD) || (! $FILE_EXTENSION =~ $ENG_WORD) ]]
then
	echo "Error: используйте английский буквы для имени файла"
	exit 1
fi

if [[ (${#FILE_NAME} -gt 7) || (${#FILE_NAME} -lt 1) ]]
then
	echo "Error: название файла от 1 до 7 символов"
    exit 1
fi

if [[ (${#FILE_EXTENSION} -gt 3) || (${#FILE_EXTENSION} -lt 1) ]]
then
	echo "Error: расширение папки от 1 до 7 символов"
    exit 1
fi


SIZE=${file_size_kb//[!0-9]/} #проверяем на содержание чисел
UNIT=${file_size_kb//[0-9]/} #проверяем на НЕсодержание чисел

FILE_SIZE=$SIZE
FILE_UNIT=$UNIT

if [[ ($FILE_SIZE -gt 100) || ($FILE_SIZE -lt 1) ]]
then
	echo "Error: max 100 kb"
	exit 1
fi

if [[ ! $FILE_UNIT =~ $UNIT_MEASURE_KB ]]
then
	echo "Error: use kb"
	exit 1
fi