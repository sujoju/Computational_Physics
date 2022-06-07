#!/bin/sh

# fine-grained for a nice M vs T plot
# rm data/MvsT.dat
# i=0.4;
# while (( `echo "$i < 5.0" | bc -l` )); do
#     echo "i: $i"
#     ./bin/assignment6_1.exe $RANDOM $i 0 | grep "T:" >> data/MvsT.dat
#     i=`echo "$i + 0.01" | bc -l`
# done;

# coarse grained for a good beta estimate
rm data/MvsT_coarse.dat
i=1.0;
while (( `echo "$i < 5" | bc -l` )); do
   echo "i: $i"
   ./bin/assignment6_1.exe $RANDOM $i 0 | grep "T:" >> data/MvsT_coarse.dat
   i=`echo "$i + 0.05" | bc -l`
done;

gnuplot ./gnuplot/assignment6_1.plt


