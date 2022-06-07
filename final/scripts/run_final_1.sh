frandomization=0.0
fdamage=0.0

alphanum=();
for n in $(seq 1 7); do 

    testp="./mystery/00${n}.dat"
    inputp=$(ls ./character_groups/00${n}/*.dat)
    ./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >& log

    # get the index from the hamming distance ...
    index=`grep "nearest" log | awk '{print $3}'` 
    letter=`grep "index: ${index}" log | awk '{print $4}' | sed -e 's,.*/,,g;s,.dat,,'`
    alphanum+=$letter
    rm log
done;

echo "The mystery word is : ${alphanum[*]}"
