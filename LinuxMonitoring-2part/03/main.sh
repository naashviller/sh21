#!/bin/bash

source delete_functions.sh

case "$1" in
    1)  delete_log;;
    2)  delete_time;;
    3)  delete_mask;;
    *)  echo "Watning: invalid parameter. Use 1, 2 or 3."
        exit 1 ;;
esac