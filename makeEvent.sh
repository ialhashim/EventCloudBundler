if [ "$#" == "0" ]; then
    echo "No arguments provided"
    exit 1
fi

./getEventMedia.sh $1 | tee output/$1_log_download.txt
./runBundler.sh $1 | tee output/$1_log_bundler.txt


