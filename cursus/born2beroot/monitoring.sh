# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:44:33 by mhaddou           #+#    #+#              #
#    Updated: 2024/12/20 18:48:53 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash

ram_status()
{
    keyw="Mem:"
    flag=-m
    read total <<< $(free $flag | grep $keyw | tr -d $keyw | na4r 1)
    read use <<< $(free $flag | grep $keyw | tr -d $keyw | na4r 2)
    
    printf "#Memory Usage: $use/$total MB"
    per=$((100 * use / total))
    printf " (%0.2f%%)\n" $per
}

_info()
{
    un_flag="--all"
    printf "#Architecture : $(uname $un_flag)\n"
}

_cpu_p()
{
    str_cpu="Socket(s):"
    printf "#CPU physical : $(lscpu | grep  $str_cpu | tr -d $str_cpu | tr -d " ")\n"
}

_v_cpu()
{
    printf "#vCPU : $(nproc $un_flag)\n"
}

_lvm() 
{
    printf "#LVM use : "
    q_lvm=$(lsblk | grep lvm | wc -l)
    if [ "$q_lvm" -eq 0 ]; then
        printf "no\n"
    else
        printf "yes\n"
    fi
}

l_boot() 
{
    ot=$(who $1)
    d=$(na4r $2 <<< "$ot")
    t=$(na4r $3 <<< "$ot")
    printf "#Last boot : %s %s\n" "$d" "$t"
}
_cpu_load()
{
    p1=$(uptime | na4r 9 | tr -d ",")
    p2=$(uptime | na4r 10 | tr -d ",")
    p3=$(uptime | na4r 11 | tr -d ",")
    sum=$(echo "$p1 + $p2 + $p3" | bc)
    printf "#CPU load : %0.2f%%\n" $sum
}

usr_l()
{
    printf "#User log : $(who | wc -l) \n"
}

_net()
{
    add_ip=$(hostname -I)
    add_mac=$(ifconfig | grep ether | na4r 2)
    printf "#network : IP $add_ip ($add_mac) \n"
}
_disk()
{
    d_use=$(df -BM --total | grep total | na4r 2 | tr -d M)
    d_total=$(df -BG --total | grep total | na4r 2)
    d_per=$(df -BG --total | grep total | na4r 5 | tr -d "%")
    printf "#Disk Usage : $d_use/$d_total"b" ($d_per%%) \n"
}

__tcp_en()
{
    flag_net="-an"
    str='ESTABLISHED'
    printf "#Connections TCP : $(netstat -an | grep $str | wc -l) $str\n"
}
c_sudo()
{
    t_n=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
    printf "#Sudo: $t_n cmd \n"
}
output=$(
_info
_cpu_p
_v_cpu
ram_status
_disk
_cpu_load
l_boot "-b" 3 4
_lvm
__tcp_en
usr_l
_net
c_sudo
)
wall "$output"
