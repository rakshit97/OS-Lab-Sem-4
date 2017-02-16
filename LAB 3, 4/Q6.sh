files=`ls -f`
for i in $files;
do
	sed -i -e 's/^ex:/Example:/' $i
	sed -i -e 's/.ex:/.Example:/' $i
done
