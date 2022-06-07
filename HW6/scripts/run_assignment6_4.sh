#!/bin/sh

TC05=$( echo "2.27 * 0.5" | bc -l )
TC095=$( echo "2.27 * 0.95" | bc -l )
TC2=$( echo "2.27 * 2" | bc -l )

./bin/assignment6_4.exe $RANDOM ${TC05} 0.0 50000 100 > ./data/correlation_TC05.dat
./bin/assignment6_4.exe $RANDOM ${TC095} 0.0 50000 100 > ./data/correlation_TC095.dat
./bin/assignment6_4.exe $RANDOM ${TC2} 0.0 50000 100 > ./data/correlation_TC2.dat

gnuplot ./gnuplot/assignment6_4.plt