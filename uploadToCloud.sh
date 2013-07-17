export AWS_ACCESS_KEY_ID=AKIAJEX7EXMYDG2LMPYA
export AWS_SECRET_ACCESS_KEY=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


if [ "$#" == "0" ]; then
    echo "No arguments provided"
    exit 1
fi


boto-rsync output/$1/bundle s3://eventfulcloud-uploads/$1/bundle
