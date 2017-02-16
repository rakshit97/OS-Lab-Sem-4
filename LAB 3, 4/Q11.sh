echo "1. Search"
echo "2. Delete"
echo "3. Exit"

read opt

case $opt in
	1)echo "Enter file"
	read file_name
	grep $1 $file_name;;
	2)echo "Enter file"
	read file_name
	sed -i -e '/$1/{d;g}' $file_name;;
	3)exit 0;;
esac
