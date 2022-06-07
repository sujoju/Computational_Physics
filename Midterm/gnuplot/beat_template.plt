set terminal png size 1000,1000
set output "img/beat_t_XXX.png"

set multiplot layout 2,1

set yrange[-1.5:1.5]
set xrange[0:4]
set arrow from 0.05, graph 0 to 0.05, graph 1 nohead
plot "data/beat_t_XXX.dat" using 4:6 w l title "y1, f: 1200Hz", "data/beat_t_XXX.dat" using 4:8 w l title "y2, f: 1320Hz"

set yrange[-3:3]
plot "data/beat_t_XXX.dat" using 4:10 w l title "y1+y2", "data/beat_sum_t_XXX.dat" using 4:6 w points title "y3"

unset multiplot
