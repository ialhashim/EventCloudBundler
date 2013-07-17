# Files of event
files=$(find data/$1/full/*.jpg)

# Resolution
r=${2:500}

# Output folder
mkdir -p output/$1/ready

for file in $files; do
	filename=${file##*/}
	convert $file -resize "$rx$r^" -gravity center -crop $rx$r+0+0 output/$1/ready/$filename
done
 
