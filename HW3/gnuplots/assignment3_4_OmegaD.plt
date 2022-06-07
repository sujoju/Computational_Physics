# Analytical Solution
l = 1.0
Omega = sqrt(9.81/l)
F_D = 0.2
q = 1
theta_0(Omega_D) = F_D/sqrt((Omega**2-Omega_D**2)**2 + (q*Omega_D)**2)

set terminal png size 1500,1000
set output "../img/assignment3_4_OmegaD.png"

set multiplot layout 2,1 

set title "Omega_D vs Max Amplitude [l = 1m, dOmegaD = 0.05]
set ylabel "theta_0 (rad)"
set xlabel "Omega_D (1/s)"

set xrange[0.667:26]
set yrange[0.0:0.07]

plot "../data/damped_driven_OmegaDvsAmp.dat" using 1:(theta_0($1)) with lines linecolor rgb "#44AA99" title "Analytical", "../data/damped_driven_OmegaDvsAmp.dat" using 1:2 with lines linecolor rgb "#CC6677" title "F_D = 0.2, q = 1"

set title "Log Plot of Omega_D vs Max Amplitude [l = 1m, dOmegaD = 0.05]"
set ylabel "theta_0 (rad)"
set xlabel "Omega_D (1/s)"

set xrange[0.667:26]
set yrange[-5:0]

plot "../data/damped_driven_OmegaDvsAmp.dat" using 1:(log10(theta_0($1))) with lines linecolor rgb "#44AA99" title "Analytical", "../data/damped_driven_OmegaDvsAmp.dat" using 1:(log10($2)) with lines linecolor rgb "#CC6677" title "F_D = 0.2, q = 1"

unset multiplot