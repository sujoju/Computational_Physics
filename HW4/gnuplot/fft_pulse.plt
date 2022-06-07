set terminal png size 1000,1000
set output "img/assignment4_2_fft_pulse.png"


set xrange [0:0.04]
set yrange [-0.6:0.6]

set xlabel "Time (s)"
set ylabel "Signal (arbitrary units)"
plot "data/fft_pulse.dat" u ($4):($6) with lines linecolor rgb "red" title "String signal versus time"

