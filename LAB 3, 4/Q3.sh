files=`find . -name "*.txt"`

for f in $files; do
	mv "$f" "$(basename "$f" .txt).text"
done
