set terminal pngcairo
set output "img/assignment6_4.png"

set xrange[1:99]
set yrange[-0.05:0.1]

set key font ",8"
set xlabel 'i'
set ylabel 'f(i) - <s>^2'

plot './data/correlation_TC05.dat' u 1:2 title "T = 0.5*T_C", \
'./data/correlation_TC095.dat' u 1:2  title "T = 095*T_C", \
'./data/correlation_TC2.dat' u 1:2  title "T = 2*T_C"