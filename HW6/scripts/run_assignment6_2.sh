#!/bin/sh

# fine-grained for a nice M vs T plot
# rm data/EvsT.dat
# i=0.4;
# while (( `echo "$i < 5.0" | bc -l` )); do
#     echo "i: $i"
#     ./bin/assignment6_2.exe $RANDOM $i 0 | grep "T:" >> data/EvsT.dat
#     i=`echo "$i + 0.01" | bc -l`
# done;

# coarse-grained for a faster M vs T plot
rm data/EvsT.dat
i=0.4;
while (( `echo "$i < 5.0" | bc -l` )); do
    echo "i: $i"
    ./bin/assignment6_2.exe $RANDOM $i 0 | grep "T:" >> data/EvsT.dat
    i=`echo "$i + 0.1" | bc -l`
done;

gnuplot ./gnuplot/assignment6_2.plt