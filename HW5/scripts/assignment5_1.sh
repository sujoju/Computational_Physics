#!/bin/sh

FDstep=0.001
FD=1.35

rm data/bifurcation.dat

while (( `echo "${FD} < 1.5" | bc` )); do 
    echo $FD;
    if (( `echo "${FD} > 1.43" | bc` )); then 
	FDstep=0.0001 
    fi
    FD=`echo "$FD + $FDstep" | bc -l `;
    ./bin/assignment5_1.exe 0.15 0.5 $FD 0.666666  >> data/bifurcation.dat     
done

gnuplot ./gnuplot/bifurcation.plt 