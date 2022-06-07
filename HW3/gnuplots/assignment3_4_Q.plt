# Analytical Solution
l = 1.0
Omega = sqrt(9.81/l)
F_D = 0.2
Omega_D = Omega
theta_0(q) = F_D/sqrt((Omega**2-Omega_D**2)**2 + (q*Omega_D)**2)

set terminal png size 1500,1000
set output "../img/assignment3_4_Q.png"

set multiplot layout 2,1 

set title "Q vs Max Amplitude [l = 1m, dQ = 0.05]
set ylabel "theta_0 (rad)"
set xlabel "Q"

set xrange[0.667:26]
set yrange[0.0:0.07]

plot "../data/damped_driven_QvsAmp.dat" using 1:(theta_0($1)) with lines linecolor rgb "#44AA99" title "Analytical", "../data/damped_driven_QvsAmp.dat" using 1:2 with lines linecolor rgb "#CC6677" title "F_D = 0.2, Omega_D = 0.667"

set title "Log Plot of Q vs Max Amplitude [l = 1m, dQ = 0.05]"
set ylabel "theta_0 (rad)"
set xlabel "Q"

set xrange[0.667:26]
set yrange[-5:0]

plot "../data/damped_driven_QvsAmp.dat" using 1:(log10(theta_0($1))) with lines linecolor rgb "#44AA99" title "Analytical", "../data/damped_driven_QvsAmp.dat" using 1:(log10($2)) with lines linecolor rgb "#CC6677" title "F_D = 0.2, Omega_D = 0.667"

unset multiplot