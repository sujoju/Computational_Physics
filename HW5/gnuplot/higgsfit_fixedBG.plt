set terminal pngcairo
set output 'img/mgg_sig_bgfixed.png'

# BG only best fit 3 param 
#Ab     = 1526.67690 +/- 32711827088299292.00000
#tau    = -20.34237 +/- 0.34487
#x0     = 102.10658 +/- 435872312452599.87500
# with BG fixed to BG only fit 
#As      = 129.65210 +/- 18.60050
#mu      = 126.21534 +/- 0.22568
#sigma   = 1.41973 +/- 0.22242


B(x) = Ab*exp((x-x0)/tau)
Ab      = 1526.67690
tau     = -20.34237
x0      = 102.10658

S(x) = As*exp(-(x-mu)**2/(2*sigma**2))
As      = 129.65210 
mu      = 126.21534 
sigma   = 1.41973 


SB(x) = B(x) + S(x)

set xrange[100:160]
set grid x y
set xlabel "m(gg)"
set ylabel "N"


plot  "data/higgs.dat" using ($1):2:3 with yerrorbars title "data", B(x) w l lc rgb "red" title "BG", SB(x) w l lc rgb "blue" title "SIG+BG"

