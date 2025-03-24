#!/bin/bash

generate_ip() {
    echo "$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256))"
}

generate_status_code() {
    status_codes=(200 201 400 401 403 404 500 501 502 503)
    echo "${status_codes[$((RANDOM % ${#status_codes[@]}))]}"
}

generate_method() {
    methods=("GET" "POST" "PUT" "PATCH" "DELETE")
    echo "${methods[$((RANDOM % ${#methods[@]}))]}"
}

generate_date() {
    start_timestamp=$(date -d "2024-02-01" +%s)
    end_timestamp=$(date -d "2024-02-01 + 1 day" +%s)
    random_timestamp=$((start_timestamp + RANDOM % (end_timestamp - start_timestamp) ))
    date -u -d "@$random_timestamp" +"%d/%b/%Y:%H:%M:%S %z"
}

generate_url() {
    urls=(" /home" " /about" " /contact" " /product" " /login")
    echo "${urls[$((RANDOM % ${#urls[@]}))]}"
}

generate_user_agent() {
    agents=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")
    echo "${agents[$((RANDOM % ${#agents[@]}))]}"
}

generate_log_entry() {
    ip=$(generate_ip)
    status_code=$(generate_status_code)
    method=$(generate_method)
    date=$(generate_date)
    url=$(generate_url)
    user_agent=$(generate_user_agent)

    echo "$ip - - [$date] \"$method$url\" $status_code - \"$user_agent\""
}

generate_logs_for_day() {
    day_logs_count=$((100 + RANDOM % 1000))
    for ((i = 0; i < day_logs_count; i++)); do
        generate_log_entry
    done
}
