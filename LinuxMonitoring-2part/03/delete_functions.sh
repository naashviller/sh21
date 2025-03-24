# delete_functions.sh

function delete_log() {
    if [ -f "log.txt" ]; then
        while IFS= read -r entry; do
            delete_entry "$entry"
        done < log.txt
    else
        echo "Warning: log was not found"
    fi
}

function delete_time() {
    read -p "Input start time (YYYY-MM-DD HH:MM): " start_time
    read -p "Input eng time (YYYY-MM-DD HH:MM): " end_time

    start_timestamp=$(date -d "$start_time" +"%s")
    end_timestamp=$(date -d "$end_time" +"%s")

    if [ $start_timestamp -ge $end_timestamp ]; then
        echo "Error: invalid time interval"
        exit 1
    fi

    while IFS= read -r entry; do
        entry_timestamp=$(date -r "$entry" +"%s")
        if [ $entry_timestamp -ge $start_timestamp ] && [ $entry_timestamp -le $end_timestamp ]; then
            delete_entry "$entry"
        fi
    done < <(find . -type f -o -type d)
}

function delete_mask() {
    read -p "Input mask: " name_mask

    while IFS= read -r entry; do
        if [[ "$entry" == *"$name_mask"* ]]; then
            delete_entry "$entry"
        fi
    done < <(find . -type f -o -type d)
    rm -f "log.txt"
}

function delete_entry() {
    if [ -d "$1" ]; then
        rm -r "$1"
        echo "Deleted: $1"
    elif [ -f "$1" ]; then
        rm "$1"
        echo "Deleted: $1"
    else
        echo "Warning: can not delete $1 - unknown file type"
    fi
    rm "log.txt"
}
