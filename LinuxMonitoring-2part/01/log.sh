#!/bin/bash

function writeLog()
{
	local currentDir=$(basename $(pwd))
	local absDir=$(pwd)
	local logFile="$currentDir.log"
	local absLog=$absDir/$logFile
	
	if [ ! -f "$absLog" ]
	then
		echo "Данные созданных папок и файлов:" > "$absLog"
	fi
	
	if [ -f "$absLog" ]
	then
		echo "Папка: $PATH_TO_FOLDER/$2 Файл: $3 Размер: $4 Единица измерения: $5 Дата создания: $1" >> "$absLog"
	fi
}
