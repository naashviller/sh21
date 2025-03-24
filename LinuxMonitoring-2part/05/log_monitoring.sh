#!/bin/bash

sort_return_code() {
    awk -v column="$1" '{print $column, $0}' "$2" | sort -n
}

get_unique_ip() {
    awk '{print $1}' "$1" | sort -u
}

error_requests() {
    awk '$8 ~ /^[45]/ {print $0}' "$1"
}
