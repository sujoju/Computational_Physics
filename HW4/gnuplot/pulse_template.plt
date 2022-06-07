set terminal png size 1000,1000
set output "img/pulse_t_XXX.png"

set yrange[-1.5:1.5]
set xrange[0:1]
set arrow from 0.05, graph 0 to 0.05, graph 1 nohead
p "data/wavedata_pulse_t_XXX.dat" u 4:6 w l title "gaussian"


