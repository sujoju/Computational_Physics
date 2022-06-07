#!/bin/sh

# run as ...
# ./scripts/run_standing.sh 200 1.5
# ./scripts/run_standing.sh 200 4.0


# number of time samples (eg: of .dat files)
n=$1

# change k ...
k=$2

echo "running : assignment4_1.exe $k"
./bin/assignment4_1.exe $k

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g;s,YYY,$k,g;s,ZZZ,$l,g" gnuplot/standing_template.plt > standing.plt
    gnuplot standing.plt
    (( i++ ))
done;

echo "animating ..."
rm data/standing_t_*.dat
magick -delay 5 $(ls img/standing_*.png | sort -t'_' -k3 -n) -loop 0 img/assignment4_1_standing_k_${k}.gif
rm img/standing_t_*.png
rm standing.plt

