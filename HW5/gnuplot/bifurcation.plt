set terminal pngcairo

set ylabel "theta(radians)
set xlabel "FD"

set yrange [1.0:3.5]
set output "img/assignment5_1.png"
plot "data/bifurcation.dat" using 2:4 with dots title "bifurcation : theta vs FD"

set xrange [1.47:1.49]
set yrange [1.0:3.5]
set output "img/assignment5_1_zoom.png"
plot "data/bifurcation.dat" using 2:4 with points pointtype 10 pointsize 0.15 title "bifurcation : theta vs FD"
