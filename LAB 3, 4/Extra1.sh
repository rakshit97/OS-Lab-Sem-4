count=0
for((i=1;i<=$1;i++));do
	rem=$(($1 % $i))
	if [ $rem == 0 ];then
		((count++))
	fi
done
if [ $count == 2 ];then
	echo "Prime number"
else
	echo "Not a prime number"
fi	
