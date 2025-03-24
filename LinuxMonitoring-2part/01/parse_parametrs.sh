#!/bin/bash

FIVE=$5

if [[ ! $FIVE =~ $DOT ]]
then
	echo "$ERR_DOT"
	exit 1
fi

BEFORE_DOT=${FIVE%.*} #имя
AFTER_DOT=${FIVE#*.} #расширение

FILE_NAME=$BEFORE_DOT
FILE_EXTENSION=$AFTER_DOT

if [[ (! $FILE_NAME =~ $ENG_WORD) || (! $FILE_EXTENSION =~ $ENG_WORD) ]]
then
	echo "$ERR_ENG"
	exit 1
fi

if [[ (${#FILE_NAME} -gt 7) || (${#FILE_NAME} -lt 1) ]]
then
	echo "$ERR_RANGE"
    exit 1
fi

if [[ (${#FILE_EXTENSION} -gt 3) || (${#FILE_EXTENSION} -lt 1) ]]
then
	echo "$ERR_LITTLE_RANGE"
    exit 1
fi

SIX=$6

SIZE=${SIX//[!0-9]/} #проверяем на содержание чисел
UNIT=${SIX//[0-9]/} #проверяем на НЕсодержание чисел

FILE_SIZE=$SIZE
FILE_UNIT=$UNIT

if [[ ($FILE_SIZE -gt 100) || ($FILE_SIZE -lt 1) ]]
then
	echo "$ERR_BIG_RANGE"
	exit 1
fi

if [[ ! $FILE_UNIT =~ $UNIT_MEASURE_KB ]]
then
	echo "$ERR_KB"
	exit 1
fi
