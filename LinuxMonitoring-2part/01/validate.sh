#!/bin/bash
 
COUNT_FOLDERS=$2
LETTERS_OF_FOLDER=$3
COUNT_FILES=$4
 
if [[ $COUNT_FOLDERS != $ONLY_NUMBER ]]
then
	echo "$ERR_SUBFOLDERS"
	exit 1
fi

if [[ ! $LETTERS_OF_FOLDER =~ $ENG_WORD ]]
then
	echo "$ERR_ENG"
	exit 1
fi

if [[ (${#LETTERS_OF_FOLDER} -gt 7) || (${#LETTERS_OF_FOLDER} -lt 1) ]]
then
	echo "$ERR_RANGE"
    exit 1
fi

if [[ $COUNT_FILES != $ONLY_NUMBER ]]
then
	echo "$ERR_FILES"
	exit 1
fi

source parse_parametrs.sh
