#!/bin/sh

T=$( echo "2.27*0.95" | bc -l )

datdir=$1
datdir="$datdir/timeseries_T_${T}"
if [ -e $datdir ]; then rm -rf $datdir; fi 
mkdir $datdir

imgdir=$2
imgdir="$imgdir/timeseries_T_${T}"
if [ -e $imgdir ]; then rm -rf $imgdir; fi 
mkdir $imgdir

./bin/assignment6_5.exe $RANDOM $T 0 200 100 $datdir | grep 'i:' > $datdir/MvsTime.dat
./scripts/make_timeseries_plots.sh $datdir $imgdir 
