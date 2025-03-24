#!/bin/bash

source check_space.sh

source log.sh

timestamp=$(date +%d%m%y)

function createName()
{
	local letters=$1 #параметр с буквами
	
    local rand_letter=${letters:$((RANDOM % ${#letters})):1}
	
	local position=$(expr index "$letters" "$rand_letter")
	#Номер позиции первого совпадения в $letters c первым символом в $rand_letter
	
    local before="${letters:0:position-1}"
	#с начала и до совпадения
    local after="${letters:position-1}"
	#после совпадения
	
	after="${rand_letter}${after}"
	
	letters="${before}${after}"
	echo $letters
	
}

function createFolder()
{
	local newName=$1 #переменная с генерированным новым именем (сразу кладем переданные буквы)
	local fold=""
	local length=$2
	
	local flag=1
	
	while [ ! $flag -eq 0 ]
	do
		while [ ${#newName} -lt $length ]
		do
			newName=$(createName $newName)
		done

		fold="${newName}_${timestamp}"

		if [ -d "$fold" ]
		then
			newName=$(createName $newName)
		else
			mkdir "${fold}"
			flag=0
		fi
	done
	
	echo $fold
}

function createFile()
{
	local newName=$1 #переменная с генерированным новым именем (сразу кладем переданные буквы)
	local ext=$2
	local fil=""
	local length=$3
	local size=$4
	local unitMeasure=$5
	
	local flag=1
	
	while [ ! $flag -eq 0 ]
	do
		while [ ${#newName} -lt $length ]
		do
			newName=$(createName $newName)
		done

		fil="${newName}_${timestamp}"

		if [ -f "${fil}.${ext}" ]
		then
			newName=$(createName $newName)
		else
			if [ $unitMeasure == "kb" ] #здесь проверяем на единицу измерения файла (k - килобайты, m - мегабайты) - в данном случае килобайты
			then
				truncate -s "$size"k "${fil}.${ext}"
			fi
			flag=0
		fi
	done
	
	echo "$fil.$ext"
}

NAME_LENGTH=4

CURRENT_PROJECT_DIR=$(pwd) #сохраняем инфу о текущей папке со скриптом, чтобы правильно потом записывать логи

cd $PATH_TO_FOLDER
for (( i=1; i<=$COUNT_FOLDERS; i++ ))
do
	checkSpace
	resultFolder=$(createFolder $LETTERS_OF_FOLDER $NAME_LENGTH)
	for (( j=1; j<=$COUNT_FILES; j++ ))
	do
		checkSpace
		: '
		т.к. writeLog() будет запускаться внутри созданных папок, то нам надо переходить
		обратно в папку проекта, чтобы записывать в логи. т.е. в цикле мы постоянно
		"ходим" по папкам туда-сюда:
		'
		cd $resultFolder
		resultFile=$(createFile $FILE_NAME $FILE_EXTENSION $NAME_LENGTH $FILE_SIZE $FILE_UNIT)
		cd $CURRENT_PROJECT_DIR
		writeLog $timestamp $resultFolder $resultFile $FILE_SIZE $FILE_UNIT
		cd $PATH_TO_FOLDER
	done
done
