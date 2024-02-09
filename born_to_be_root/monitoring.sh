SUDO_CNT=$(cat '/var/log/sudo/seq')
RESULT=$(echo "obase=10; ibase=36; $SUDO_CNT" | bc)

FLAG="$(lvscan | wc -l)"
if [ $FLAG > 0 ]; then
	result="yes"
else
	result="no"
fi

DISK_AVAIL=$(df -P | grep -v ^Filesystem | awk '{sum += $4} END {print sum;}')
DISK_USED=$(df -P | grep -v ^Filesystem | awk '{sum += $3} END {print sum;}')
DISK_PER=`echo "100*$DISK_USED/$DISK_AVAIL" | bc -l`
DISK_PER=$(printf "%.2f" $DISK_PER)
DISK_AVAIL_GB=`echo "$DISK_AVAIL/1024/1024" | bc -l`
DISK_AVAIL_GB=$(printf "%.0f" $DISK_AVAIL_GB)
DISK_USED_MB=`echo "$DISK_USED/1024" | bc -l`
DISK_USED_MB=$(printf "%.0f" $DISK_USED_MB)

MEM_AVAIL=$(free -m | awk 'NR==2{print $4}')
MEM_USED=$(free -m | awk 'NR==2{print $3}')
MEM_PER=`echo "100*$MEM_USED/$MEM_AVAIL" | bc -l`
MEM_PER=$(printf "%.2f" $MEM_PER)

CPU_LOAD=$(mpstat | tail -1 | awk '{print 100-$NF}')
CPU_LOAD=$(printf "%.1f" $CPU_LOAD)

ARCHITECTURE="\t#Architecture : $(uname -a)"
PHYSICAL_CPU="\t#CPUs physical : $(lscpu | grep -w CPU\(s\) | awk 'NR==1{print $2}')"
VIRTUAL_CPU="\t#vCPU : $(nproc)"
MEM_USAGE="\t#Memory Usage : "$MEM_USED/$MEM_AVAIL"MB ($MEM_PER%)"
DISK_USAGE="\t#Disk Usage : "$DISK_USED_MB/$DISK_AVAIL_GB"GB ($DISK_PER%)"
CPU_LOAD="\t#CPU load : $CPU_LOAD%"
LAST_BOOT="\t#Last boot : $(who -b | awk '{print $3,$4}')"
LVM_USE="\t#LVM use : $result"
TCP_CONNECTIONS="\t#Connections TCP : $(netstat -nt -A inet | grep tcp | wc -l) ESTABLISHED"
USER_LOG="\t#User log : $(users | wc -w)"
NETWORK="\t#Network : IP $(hostname -I)($(ifconfig | grep -w "ether" | awk 'NR==1{print $2}'))"
SUDO_CMD="\t#Sudo : $RESULT cmd"
echo -e "$ARCHITECTURE\n$PHYSICAL_CPU\n$VIRTUAL_CPU\n$MEM_USAGE\n$DISK_USAGE\n$CPU_LOAD\n$LAST_BOOT\n$LVM_USE\n$TCP_CONNECTIONS\n$USER_LOG\n$NETWORK\n$SUDO_CMD" | wall
