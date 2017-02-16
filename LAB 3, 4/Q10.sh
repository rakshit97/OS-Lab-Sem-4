case $2 in
	"-wordcount")wc $1 -w;;
	"-linecount")wc $1 -l;;
	"-charcount")wc $1 -c;;
esac
