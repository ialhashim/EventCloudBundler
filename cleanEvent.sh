if [ "$#" == "0" ]; then
    echo "No arguments provided"
    exit 1
fi


sudo rm -f -R output/$1
sudo rm -f output/$1_*


if [ "$2" = "all" ]; then
	sudo rm -f -R data/$1
	sudo rm -f data/$1_*
fi

