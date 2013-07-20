# Files of event
files=$(find data/$1/full/*.jpg)

# Resolution
r=${2:-0}

# Output folder
mkdir -p output/$1

for file in $files; do
	filename=${file##*/}

	if [ $r -eq 0 ] 
	then
		cmmand="convert $file output/$1/$filename"
	else
		cmmand="convert $file -resize "${r}x${r}^" output/$1/$filename"
	fi	

	echo $cmmand
	$cmmand
done
 
echo "Files converted."
