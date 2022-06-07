set terminal pngcairo
set output 'img/mgg_sig_bg2comp.png'

# 2 component BG
#As      = 133.31455 +/- 17.42455
#mu      = 126.17796 +/- 0.23410
#sigma   = 1.63495 +/- 0.23832
#Ab      = 1687.23244 +/- 14.63853
#tau     = -20.08283 +/- 0.16297



B(x) = Ab*exp((x-x0)/tau)
Ab      = 1687.23244
tau     = -20.08283 
x0      = 100.0

S(x) = As*exp(-(x-mu)**2/(2*sigma**2))
As      = 133.31455
mu      = 126.17796
sigma   = 1.63495


SB(x) = B(x) + S(x)

set xrange[100:160]
set grid x y
set xlabel "m(gg)"
set ylabel "N"


plot  "data/higgs.dat" using ($1):2:3 with yerrorbars title "data", B(x) w l lc rgb "red" title "BG", SB(x) w l lc rgb "blue" title "SIG+BG"
