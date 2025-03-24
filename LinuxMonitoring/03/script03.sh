#!/bin/bash

chmod +x ./script_color.sh
source ./script_color.sh
clr_1=$(bg_color $1)
clr_2=$(color $2)
clr_3=$(bg_color $3)
clr_4=$(color $4)

echo -e "$clr_1$clr_2 HOSTNAME =${NORMAL}$clr_3$clr_4 $HOSTNAME${NORMAL}
$clr_1$clr_2 TIMEZONE =${NORMAL}$clr_3$clr_4 $(timedatectl | awk '(NR == 4){print $3}')${NORMAL}
$clr_1$clr_2 USER =${NORMAL}$clr_3$clr_4 $USER${NORMAL}
$clr_1$clr_2 OS =${NORMAL}$clr_3$clr_4 `cat /etc/issue`${NORMAL}
$clr_1$clr_2 DATE =${NORMAL}$clr_3$clr_4 `date +%d\ %B\ %Y\ %k:%M:%S`${NORMAL}
$clr_1$clr_2 UPTIME =${NORMAL}$clr_3$clr_4 $(uptime -p)${NORMAL}
$clr_1$clr_2 UPTIME_SEC =${NORMAL}$clr_3$clr_4 $(cat /proc/uptime | awk '{print $1}')${NORMAL}
$clr_1$clr_2 IP =${NORMAL}$clr_3$clr_4 $(ifconfig | grep netmask | awk '(NR == 1){print $2}')${NORMAL}
$clr_1$clr_2 MASK =${NORMAL}$clr_3$clr_4 $(ifconfig | grep netmask | awk '(NR == 1){print $4}')${NORMAL}
$clr_1$clr_2 GATEWAY =${NORMAL}$clr_3$clr_4 $(ip r | grep default | awk '{print $3}')${NORMAL}"

tmp_1=$(free | grep Mem | awk '{print $2}')
tmp_2=1048576
tmp=$(bc<<<"scale=3;$tmp_1/$tmp_2")
printf "$clr_1$clr_2 RAM_TOTAL =${NORMAL}$clr_3$clr_4 %s GB${NORMAL}\n" $tmp

tmp_3=$(free | grep Mem | awk '{print $3}')
tmp=$(bc<<<"scale=3;$tmp_3/$tmp_2")
printf "$clr_1$clr_2 RAM_USED =${NORMAL}$clr_3$clr_4 %s GB${NORMAL}\n" $tmp

tmp_4=$(free | grep Mem | awk '{print $4}')
tmp=$(bc<<<"scale=3;$tmp_4/$tmp_2")
printf "$clr_1$clr_2 RAM_FREE =${NORMAL}$clr_3$clr_4 %s GB${NORMAL}\n" $tmp

tmp_5=$(df | grep "/$" | awk '{print $2}')
tmp=$(bc<<<"scale=2;$tmp_5/1024")
printf "$clr_1$clr_2 SPACE_ROOT =${NORMAL}$clr_3$clr_4 %s MB${NORMAL}\n" $tmp

tmp_6=$(df | grep "/$" | awk '{print $3}')
tmp=$(bc<<<"scale=2;$tmp_6/1024")
printf "$clr_1$clr_2 SPACE_ROOT_USED =${NORMAL}$clr_3$clr_4 %s MB${NORMAL}\n" $tmp

tmp_7=$(df | grep "/$" | awk '{print $4}')
tmp=$(bc<<<"scale=2;$tmp_7/1024")
printf "$clr_1$clr_2 SPACE_ROOT_FREE =${NORMAL}$clr_3$clr_4 %s MB${NORMAL}\n" $tmp
