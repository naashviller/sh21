#!/bin/bash
# Получение метрик системы
cpu_usage=$(vmstat 1 2 | tail -1 | awk '{print 100 - $15}')
mem_usage=$(free -m | awk 'NR==2{printf "%d\n", $3/$2*100}')
disk_usage=$(df -h / | tail -1 | awk '{print $5}')

# Формирование HTML-страницы в формате Prometheus
html="""
<html>
  <head>
    <title>Метрики системы</title>
  </head>
  <body>
    <h1>Метрики системы</h1>
    <ul>
      <li>Использование ЦП: ${cpu_usage}%</li>
      <li>Использование памяти: ${mem_usage}%</li>
      <li>Использование диска: ${disk_usage}</li>
    </ul>
  </body>
</html>
"""
# Сохранение HTML-страницы
echo "$html" > /tmp/metrics.html

# Запуск nginx для предоставления страницы
nginx -c /etc/nginx/nginx.conf