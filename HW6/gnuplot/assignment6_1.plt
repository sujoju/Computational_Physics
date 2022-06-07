set terminal pngcairo
set output "img/assignment6_1.png"

set ylabel "Magnetization"
set xlabel "Temperature"

plot 'data/MvsT_coarse.dat' u 2:4 title "100x100 lattice" w p  pt 6 lc rgb "red"
