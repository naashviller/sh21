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

function search {
    clr_1=$(awk -F= '/^column1_background/ {print $2}' default_color.txt)
    clr_2=$(awk -F= '/^column1_font_color/ {print $2}' default_color.txt)
    clr_3=$(awk -F= '/^column2_background/ {print $2}' default_color.txt)
    clr_4=$(awk -F= '/^column2_font_color/ {print $2}' default_color.txt)
}

function default_color {
    if [ -z "$clr_1" ]
    then
        clr_1=2
    fi
    if [ -z "$clr_2" ]
    then
        clr_2=3
    fi
    if [ -z "$clr_3" ]
    then
        clr_3=4
    fi
    if [ -z "$clr_4" ]
    then
        clr_4=5
    fi
}

function outputcolor {
    if [ $1 -eq 1 ]
    then
        echo "white"
    elif [ $1 -eq 2 ]
    then
        echo "red"
    elif [ $1 -eq 3 ]
    then
        echo "green"
    elif [ $1 -eq 4 ]
    then
        echo "blue"
    elif [ $1 -eq 5 ]
    then
        echo "purple"
    elif [ $1 -eq 6 ]
    then
        echo "black"
    fi
}

