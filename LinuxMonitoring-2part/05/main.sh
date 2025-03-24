#!/bin/bash

# log_parser.sh

source log_monitoring.sh

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <1|2|3|4>"
    exit 1
fi

case "$1" in
    1) #по коду ответа
        sort_return_code 8 nginx_* ;;
    2) # уникальные IP
        get_unique_ip nginx_* ;;
    3) # запросы с ошибками (код ответа - 4хх или 5хх)
        error_requests nginx_* ;;
    4) # уникальные IP среди ошибочных запросов
        get_unique_ips < <(filter_error_requests nginx_*) ;;
    *) echo "Warning: Invalid parameter. Use 1, 2, 3 or 4."
        exit 1 ;;
esac
