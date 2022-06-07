set terminal pngcairo size 1000,500
set output ofile

set multiplot layout 1,2

set yrange[-1:101]
set xrange[-1:101]
plot ifile using ($4):($8>0?$6:1/0) w p pt 7 ps 0.4 lc rgb "blue" notitle, ifile using ($4):($8<0?$6:1/0) w p pt 7 ps 0.4 lc rgb "red" notitle


set yrange[-1:1]
set xrange[0:201]
set xlabel "time"
set ylabel "M"
plot mfile u 2:4 every 1::0::endsweep w l lc rgb "red" notitle


unset multiplot 
