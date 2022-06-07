set terminal pngcairo
set output "img/assignment6_3.png"

set ylabel "Specific Heat per Spin"
set xlabel "Temperature"

set arrow from 2.27, graph 0 to 2.27, graph 1 nohead

plot 'data/specific_heat_20.dat' u 2:4 w linespoints, \
'data/specific_heat_50.dat' u 2:4 w linespoints, \
'data/specific_heat_100.dat' u 2:4 w linespoints
