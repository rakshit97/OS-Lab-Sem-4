files=`ls *$1`
`mkdir $2`
for i in $files;
do
	`mv $i ./$2/`
done
