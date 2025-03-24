#!/bin/bash

PATH_TO_FOLDER=$1

if [ ! -n "$PATH_TO_FOLDER" ]
then
	echo "$ERR_EMPTY"
	exit 1
fi

if [ -n "$7" ]
then
	echo "$ERR_COUNT"
	exit 1
fi

if [ ! -d "$PATH_TO_FOLDER" ]
then
	echo "$ERR_DIR"
	exit 1
fi
