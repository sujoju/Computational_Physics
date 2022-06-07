# Analytical Solution
theta_0 = 0.15
l = 1.0
Omega = sqrt(9.81/l)
sol(t) = theta_0*sin(Omega*t + pi/2)

set terminal png size 1500,1000
set output "../img/assignment3_3_all.png"

set multiplot layout 3,1

set title "SHO using Euler, RKO2, and RKO4 [l = 1m, dt = 0.04s, m = 1kg]"
set ylabel "theta (rad)"
set xlabel "time (s)"

set xrange[0:10]
set yrange[-2:2]

plot "../data/sho_rkO2.dat" using 1:(sol($1)) with lines linecolor rgb "#117733" title "Analytical", "../data/sho_euler.dat" using 1:2 with lines linecolor rgb "#332288" title "Euler", "../data/sho_rkO2.dat" using 1:2 with lines linecolor rgb "#999933" title "RKO2", "../data/sho_rkO4.dat" using 1:2 with lines linecolor rgb "#CC6677" title "RKO4"

set title "Relative Error Euler, RKO2, and RKO4 [l = 1m, dt = 0.04s, m = 1kg]"
set ylabel "theta (rad)"
set xlabel "time (s)"

set xrange[0:10]
set yrange[-2:2]

plot "../data/sho_euler.dat" using 1:(sol($1) - $2) with lines linecolor rgb "#332288" title "Euler", "../data/sho_rkO2.dat" using 1:(sol($1) - $2) with lines linecolor rgb "#999933" title "RKO2", "../data/sho_rkO4.dat" using 1:(sol($1) - $2) with lines linecolor rgb "#CC6677" title "RKO4"

set title "SHO Energy using Euler, RKO2, and RKO4 [l = 1m, dt = 0.04s, m = 1kg]"
set ylabel "Energy (J)"
set xlabel "time (s)"

set xrange[0:10]
set yrange[0:6]

plot "../data/sho_euler.dat" using 1:4 with lines linecolor rgb "#332288" title "Euler", "../data/sho_rkO2.dat" using 1:4 with lines linecolor rgb "#999933" title "RKO2", "../data/sho_rkO4.dat" using 1:4 with lines linecolor rgb "#CC6677" title "RKO4"

unset multiplot