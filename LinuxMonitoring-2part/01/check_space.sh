#!/bin/bash

function checkSpace()
{
    local limit=1048576
    local space_available=$(df -k | grep /$ | awk '{print $4}')
    if [ $space_available -lt $limit ]
    then
        echo "Памяти < 1 Гб"
        exit 1
    fi
}
