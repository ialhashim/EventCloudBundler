echo_and_run() { echo "$@"; "$@"; }

d=$(pwd)
injection="BUNDLER_BIN_PATH=$d/bundler/bin"

cd output/$1

echo "~ Bundle2PMV  ~"
../../bundler/bin/Bundle2PMVS list.txt bundle/bundle.out
echo "~ Done B2MPV ~"


# Replace with path
sed "4s,.*,$injection," -i pmvs/prep_pmvs.sh

echo "~ Prepare PMVS ~"
sh pmvs/prep_pmvs.sh
echo "~ DonePreparePMV ~"

# Run Extras
echo "~ Run CMVS ~"
../../CMVS-PMVS/bin/cmvs pmvs/
echo "~ Done CMVS ~"

echo "~ Run genOption ~"
../../CMVS-PMVS/bin/genOption pmvs/
echo "~ done genopt ~"

echo "~ [Running PMVS, please wait..] ~"
#../../CMVS-PMVS/bin/pmvs2 pmvs/ option-0000
(echo -n  "../../CMVS-PMVS/bin/"; cat pmvs/pmvs.sh) > temp.sh
sh temp.sh

#return to orginal directory
cd ../..
