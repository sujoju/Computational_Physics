#!/bin/sh

#generate the wave data
./bin/assignment4_2.exe 


# number of time samples (eg: of .dat files)
n=200

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g;" ./gnuplot/pulse_template.plt > pulse.plt
    gnuplot pulse.plt
    (( i++ ))
done;

echo "animating ..."
rm data/wavedata_pulse_t_*.dat
magick -delay 10 $(ls img/pulse_*.png | sort -t'_' -k3 -n) -loop 0 img/assignment4_2_pulse.gif
rm img/pulse_t_*.png
rm pulse.plt
