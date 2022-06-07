set xrange [0:30000]
set yrange [0:15000]

set terminal png
set output "../img/assignment3_2.png"

set title "Trajectory [vi=700 m/s, B2/m=4e-5 m^-1, a=6.5e-3 K/m, alpha=2.5]"
set xlabel "x(km)"
set ylabel "y(km)"


plot "../data/drag_adiabatic_20.dat" using 2:3 with lines linecolor rgb "#332288" title "20 deg, w/ correction", "../data/drag_adiabatic_30.dat" using 2:3 with lines linecolor rgb "#88CCEE" title "30 deg, w/ correction", "../data/drag_adiabatic_40.dat" using 2:3 with lines linecolor rgb "#44AA99" title "40 deg, w/ correction", "../data/drag_adiabatic_45.dat" using 2:3 with lines linecolor rgb "#117733" title "45 deg, w/ correction", "../data/drag_adiabatic_50.dat" using 2:3 with lines linecolor rgb "#999933" title "50 deg, w/ correction","../data/drag_adiabatic_60.dat" using 2:3 with lines linecolor rgb "#DDCC77" title "60 deg, w/ correction", "../data/drag_adiabatic_70.dat" using 2:3 with lines linecolor rgb "#CC6677" title "70 deg, w/ correction",  "../data/drag_20.dat" using 2:3 with dots linecolor rgb "#332288" title "20 deg, w/o correction", "../data/drag_30.dat" using 2:3 with dots linecolor rgb "#88CCEE" title "30 deg, w/o correction","../data/drag_40.dat" using 2:3 with dots linecolor rgb "#44AA99" title "40 deg, w/o correction","../data/drag_45.dat" using 2:3 with dots linecolor rgb "#117733" title "45 deg, w/o correction","../data/drag_50.dat" using 2:3 with dots linecolor rgb "#999933" title "50 deg, w/o correction","../data/drag_60.dat" using 2:3 with dots linecolor rgb "#DDCC77" title "60 deg, w/o correction","../data/drag_70.dat" using 2:3 with dots linecolor rgb "#CC6677" title "70 deg, w/o correction"
