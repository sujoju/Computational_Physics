#!/bin/sh

i=1.0;
rm data/specific_heat_20.dat
while (( `echo "$i < 5" | bc -l` )); do
    ./bin/assignment6_3.exe $RANDOM $i 0 20 | grep "T:" >> data/specific_heat_20.dat
    i=`echo "$i + 0.1" | bc -l`
done;

i=1.5;
rm data/specific_heat_50.dat
while (( `echo "$i < 3.0" | bc -l` )); do
    ./bin/assignment6_3.exe $RANDOM $i 0 50 | grep "T:" >> data/specific_heat_50.dat
    i=`echo "$i + 0.05" | bc -l`
done;

i=2.0;
rm data/specific_heat_100.dat
while (( `echo "$i < 2.4" | bc -l` )); do
    ./bin/assignment6_3.exe $RANDOM $i 0 100 | grep "T:" >> data/specific_heat_100.dat
    i=`echo "$i + 0.01" | bc -l`
done;

gnuplot ./gnuplot/assignment6_3.plt