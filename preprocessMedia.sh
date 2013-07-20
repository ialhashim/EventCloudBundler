# Files of event
files=$(find data/$1/full/*.jpg)

# Resolution
r=${2:-500}

# Output folder
mkdir -p output/$1

for file in $files; do
	filename=${file##*/}
	cmmand="convert $file -resize "${r}x${r}^" output/$1/$filename"
	echo $cmmand
	$cmmand
done
 
echo "Files converted."
