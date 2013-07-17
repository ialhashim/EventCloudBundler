export AWS_ACCESS_KEY_ID=AKIAJEX7EXMYDG2LMPYA
export AWS_SECRET_ACCESS_KEY=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

boto-rsync -v s3://eventfulcloud-uploads/$1 data/$1
