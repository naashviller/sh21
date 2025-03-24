#!/bin/bash

echo "HOSTNAME = $HOSTNAME
TIMEZONE = $(timedatectl | awk '(NR == 4){print $3}')
USER = $USER
OS = $(cat /etc/issue)
DATE = `date +%d\ %B\ %Y\ %k:%M:%S`
UPTIME = $(uptime -p)
UPTIME_SEC = $(cat /proc/uptime | awk '{print $1}')
IP = $(ifconfig | grep netmask | awk '(NR == 1){print $2}')
MASK = $(ifconfig | grep netmask | awk '(NR == 1){print $4}')
GATEWAY = $(ip r | grep default | awk '{print $3}')"

tmp_1=$(free | grep Mem | awk '{print $2}')
tmp_2=1048576
tmp=$(bc<<<"scale=3;$tmp_1/$tmp_2")#bc типа калькулятор, scale - знак после зап
printf 'RAM_TOTAL = %s GB\n' $tmp

tmp_3=$(free | grep Mem | awk '{print $3}')
tmp=$(bc<<<"scale=3;$tmp_3/$tmp_2")
printf 'RAM_USED = %s GB\n' $tmp

tmp_4=$(free | grep Mem | awk '{print $4}')
tmp=$(bc<<<"scale=3;$tmp_4/$tmp_2")
printf 'RAM_FREE = %s GB\n' $tmp

tmp_5=$(df | grep "/$" | awk '{print $2}')
tmp=$(bc<<<"scale=2;$tmp_5/1024")
printf 'SPACE_ROOT = %s MB\n' $tmp

tmp_6=$(df | grep "/$" | awk '{print $3}')
tmp=$(bc<<<"scale=2;$tmp_6/1024")
printf 'SPACE_ROOT_USED = %s MB\n' $tmp

tmp_7=$(df | grep "/$" | awk '{print $4}')
tmp=$(bc<<<"scale=2;$tmp_7/1024")
printf 'SPACE_ROOT_FREE = %s MB\n' $tmp
