#!/bin/bash

WHITE='\033[37m'
RED='\033[31m'
GREEN='\033[32m'
BLUE='\033[34m'
PURPLE='\033[35m'
BLACK='\033[30m'

NORMAL='\033[0m'

BGWHITE='\033[47m'
BGRED='\033[41m'
BGGREEN='\033[42m'
BGBLUE='\033[44m'
BGPURPLE='\033[45m'
BGBLACK='\033[40m'

function color {
    if [ $1 -eq 1 ]
    then
        echo "${WHITE}"
    elif [ $1 -eq 2 ]
    then
        echo "${RED}"
    elif [ $1 -eq 3 ]
    then
        echo "${GREEN}"
    elif [ $1 -eq 4 ]
    then
        echo "${BLUE}"
    elif [ $1 -eq 5 ]
    then
        echo "${PURPLE}"
    elif [ $1 -eq 6 ]
    then
        echo "${BLACK}"
    fi
}

function bg_color {
    if [ $1 -eq 1 ]
    then
        echo "${BGWHITE}"
    elif [ $1 -eq 2 ]
    then
        echo "${BGRED}"
    elif [ $1 -eq 3 ]
    then
        echo "${BGGREEN}"
    elif [ $1 -eq 4 ]
    then
        echo "${BGBLUE}"
    elif [ $1 -eq 5 ]
    then
        echo "${BGPURPLE}"
    elif [ $1 -eq 6 ]
    then
        echo "${BGBLACK}"
    fi
}
