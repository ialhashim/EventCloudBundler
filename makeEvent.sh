export AWS_ACCESS_KEY_ID=AKIAJEX7EXMYDG2LMPYA
export AWS_SECRET_ACCESS_KEY=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


if [ "$#" == "0" ]; then
    echo "No arguments provided"
    exit 1
fi

./getEventMedia.sh $1 | tee output/$1_log_download.txt
./preprocessMedia.sh $1 $2 | tee output/$1_log_preprocess.txt
./runBundler.sh $1 | tee output/$1_log_bundler.txt
./runPMVS.sh $1 | tee output/$1_log_PMVS.txt
./uploadToCloud.sh $1 | tee output/$1_upload_results.txt

