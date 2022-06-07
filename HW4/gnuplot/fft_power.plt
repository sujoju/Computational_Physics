set terminal png size 2000,1000
set output "img/assignment4_2_fft_power_pulse.png"

set multiplot layout 1, 2 

set xrange [0:3000]
set xlabel "Frequency (Hz)"
set ylabel "Power (arbitrary units)"

plot "data/fft_pulse.dat" u ($2/(1000*.000033)):(($8*$8)+($10*$10)) title "Power spectrum" with linespoints linecolor rgb "red"

set xrange [0:3000]
set xlabel "Frequency (Hz)"
set ylabel "Power (arbitrary units)"

plot "data/fft_pulse.dat" u ($2/(1000*.000033)):(($8*$8)+($10*$10)) title "Power spectrum (Center)" with linespoints linecolor rgb "red", "data/fft_pulse_offcenter.dat" u ($2/(1000*.000033)):(($8*$8)+($10*$10)) title "Power spectrum (Off-Center)" with linespoints linecolor rgb "blue"

#clear 

unset multiplot