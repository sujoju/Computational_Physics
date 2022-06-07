#!/bin/sh

# run as ...
# 


# number of time samples (eg: of .dat files)
n=$1

# change k1 ...
k1=$2

k2=$3

echo "running : midterm_2.exe $k1 $k2"
./bin/midterm_2.exe $k1 $k2

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g" gnuplot/beat_template.plt > gnuplot/beat.plt
    gnuplot gnuplot/beat.plt
    (( i++ ))
done;

echo "animating ..."
rm data/beat_t_*.dat
rm data/beat_sum_t_*.dat
# magick -delay 5 $(ls img/freewave_t_*.png | sort -t'_' -k3 -n) -loop 0 img/beat_k_${k1}_${k2}.gif
ffmpeg -framerate 25 -i img/beat_t_%00d.png -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p img/beat_k_${k1}_${k2}.mp4
rm img/beat_t_*.png
rm gnuplot/beat.plt

