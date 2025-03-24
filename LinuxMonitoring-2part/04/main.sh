#!/bin/bash

source log_generator.sh

for ((day = 1; day <= 5; day++)); do
    filename="nginx_$day.log"
    generate_logs_for_day > "$filename"
    echo "Log file generated: $filename"
done

#Комментарии к кодам ответа:
#200: OK - успешный запрос.
#201: Created - успешное создание ресурса.
#400: Bad Request - некорректный запрос от клиента.
#401: Unauthorized - необходима аутентификация пользователя.
#403: Forbidden - доступ к ресурсу запрещен.
#404: Not Found - ресурс не найден.
#500: Internal Server Error - внутренняя ошибка сервера.
#501: Not Implemented - сервер не поддерживает функциональность, необходимую для выполнения запроса.
#502: Bad Gateway - сервер, действуя в качестве шлюза или прокси, получил недопустимый ответ от вышестоящего сервера.
#503: Service Unavailable - сервер временно не может обработать запрос.
