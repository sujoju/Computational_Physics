set terminal png size 1500,500
set output "img/midterm_1.png"

set grid
set logscale xy
set format y "10^{%L}"
set format x "10^{%L}"

set multiplot layout 1,3

set title "Precision vs. Granularity"
set xlabel "t steps"
set ylabel "|relative error|"
set xrange[1e1:1e7]
set yrange[1e-12:1e2]

plot "./data/decay_euler_perf.dat" using 2:3 title "euler" with points, "./data/decay_rkO2_perf.dat" using 2:3 title "rkO2" with points, "./data/decay_rkO4_perf.dat" using 2:3 title "rkO4" with points

set title "Precision vs. Cost"
set xlabel "# instructions"
set ylabel "|relative error|"
set xrange[1e5:1e8]
set yrange[1e-12:1e2]

plot "./data/decay_euler_perf.dat" using 5:3 title "euler" with points, "./data/decay_rkO2_perf.dat" using 5:3 title "rkO2" with points, "./data/decay_rkO4_perf.dat" using 5:3 title "rkO4" with points

set title "Cost vs. Granularity"
set xlabel "t steps"
set ylabel "# instructions"
set xrange[1e1:1e7]
set yrange[1e5:1e8]

plot "./data/decay_euler_perf.dat" using 2:5 title "euler" with points, "./data/decay_rkO2_perf.dat" using 2:5 title "rkO2" with points, "./data/decay_rkO4_perf.dat" using 2:5 title "rkO4" with points

unset multiplot 