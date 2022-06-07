#!/bin/sh

q_0=1.0
F=0.2
OmegaD_0=0.667
Omega=3.1321
STEP=0.05

for i in {0..500..1} 
do
    OmegaD=$(echo "scale=10; $OmegaD_0+$i*$STEP" | bc -l);
    q=$(echo "scale=10; $q_0+$i*$STEP" | bc -l);
    ./bin/assignment3_4.exe 0.15 $q_0 $OmegaD $F 0 >> ./data/damped_driven_OmegaDvsAmp.dat
    ./bin/assignment3_4.exe 0.15 $q $Omega $F 1 >> ./data/damped_driven_QvsAmp.dat
done

