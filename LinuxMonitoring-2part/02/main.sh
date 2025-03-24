#!/bin/bash

if [ "$#" -eq 3 ]; then
    
    source validate.sh

    source generate_files_folders.sh

else
    echo "Error: Передано неверное количество параметров, укажите 3 парамета
Usage: $0 <letters_in_folders> <letters_in_files> <file_weight (KB)>"
fi