if [ -d "$1" ]; then
	echo "Directory"
elif [ -f "$1" ]; then
	echo "File"
else
	echo "Not a file or directory"
fi
