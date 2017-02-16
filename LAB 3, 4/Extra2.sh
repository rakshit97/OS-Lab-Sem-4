fact=1
for((i=$1;i>0;i--));do
	fact=$(($fact * $i))
done
echo $fact
