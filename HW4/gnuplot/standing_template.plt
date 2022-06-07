set terminal png size 1000,1000
set output "img/standing_t_XXX.png"

set yrange[-2.5:2.5]
set xrange[0:1]
plot 'data/standing_t_XXX.dat' using 2:3 w l

