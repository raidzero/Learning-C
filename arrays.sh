#/bin/sh

cat /etc/fstab | grep ext > local.fstab

totalParts=`cat local.fstab | wc -l`

for i in `seq $totalParts`; do
  part[$i]=`cat local.fstab | awk '{print$2}' | sed -n ''"$i"'p'`
  echo ${part[$i]}
done


