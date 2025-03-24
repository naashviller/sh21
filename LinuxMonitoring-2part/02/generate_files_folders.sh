#!/bin/bash

folder_letters="$1"
file_letters="$2"
file_size_kb="$3"

start_date=$(date +"%d-%m-%Y#%H:%M:%S")

start_s=$(date +%s)
start_ns=$(date +%N)

source validate.sh
source log.sh

timestamp=$(date +%d%m%y)

function createName()
{
	local letters=$1
	
    local random_letter=${letters:$((RANDOM % ${#letters})):1}
	
	local position=$(expr index "$letters" "$random_letter")
	
    local before="${letters:0:position-1}"
    local after="${letters:position-1}"
	
	after="${random_letter}${after}"
	
	letters="${before}${after}"
	echo $letters
}

function createFolder()
{
	local newName=$1
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
	local newName=$1
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
			if [ $unitMeasure == "Mb" ] #здесь проверяем на единицу измерения файла (k - килобайты, m - мегабайты) - в данном случае мегабайты
			then
				truncate -s "$size"m "${fil}.${ext}"
			fi
			flag=0
		fi
	done
	
	echo "$fil.$ext"
}

NAME_LENGTH=5

CURRENT_PROJECT_DIR=$(pwd)

SYSTEM_FOLDER=$(find / -xdev -type d ! -path "*bin*" ! -path "*sbin*" 2>/dev/null)
#- исключаем другие файловые системы через "-xdev";
#- исключаем папки, которые содержат "bin" или "sbin" в пути;

for PATH_TO_FOLDER in $SYSTEM_FOLDER
do
	cd $PATH_TO_FOLDER
	for (( i=1; i<=100; i++ ))
	do
		checkSpace
		resultFolder=$(createFolder $folder_letters $NAME_LENGTH)
		randomNumber=$((RANDOM % 50 + 1))
		for (( j=1; j<=$randomNumber; j++ ))
		do
			checkSpace

			cd $resultFolder
			resultFile=$(createFile $FILE_NAME $FILE_EXTENSION $NAME_LENGTH $FILE_SIZE $FILE_UNIT)
			cd $CURRENT_PROJECT_DIR
			writeLog $timestamp $resultFolder $resultFile $FILE_SIZE $FILE_UNIT
			cd $PATH_TO_FOLDER
		done
	done
done

cd $CURRENT_PROJECT_DIR #возвращаемся сюда, чтобы корректно отработала функция extendedLog()

end_s=$(date +%s)
end_ns=$(date +%N)

duration_seconds=$((end_s - start_s))
duration_nanoseconds=$((end_ns - start_ns))
duration_one_of_ten=$((duration_nanoseconds / 100000000))

end_date=$(date +"%d-%m-%Y#%H:%M:%S")

echo "Script started working at $start_date"
echo "Script execution time (in seconds) = $duration_seconds.$duration_one_of_ten"
echo "Script ended working at $end_date"

extendedLog $start_date $duration_seconds.$duration_one_of_ten $end_date