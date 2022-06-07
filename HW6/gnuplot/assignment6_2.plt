set terminal pngcairo
set output "img/assignment6_2.png"

set ylabel "Energy per Spin"
set xlabel "Temperature"

plot 'data/EvsT.dat' u 2:4 title "100x100 lattice" w p  pt 6 lc rgb "red"
