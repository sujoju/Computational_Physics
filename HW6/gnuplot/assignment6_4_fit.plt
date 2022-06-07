set terminal pngcairo
set output 'img/assignment6_4_fit.png'

# TC05
# A     = 0.00118 +/- 10.50929
# lambda    = 0.99533 +/- 7232.49268
# b    = -0.00058 +/- 0.16820

B05(x) = A05*exp(-x/lambda05)+b05
A05      = 0.00118 
lambda05 = 0.99533 
b05      = -0.00058

# TC095
# A     = 0.08301 +/- 3.94877
# lambda    = 1.84513 +/- 94.85100
# b    = 0.00545 +/- 0.17221

B095(x) = A095*exp(-x/lambda095)+b095
A095      = 0.08301 
lambda095 = 1.84513 
b095      = 0.00545 

# TC2
# A     = 0.53074 +/- 107.10607
# lambda    = 0.46289 +/- 42.46746
# b    = 0.00008 +/- 0.16612

B2(x) = A2*exp(-x/lambda2)+b2
A2      = 0.53074 
lambda2 = 0.46289 
b2      = 0.00008 

set xrange[0:77]
set yrange[-0.05:0.1]
set grid x y


plot  "data/correlation_TC05.dat" using 1:2 title "TC05", \
B05(x) w l lc rgb "red" title "TC05 fit", \
"data/correlation_TC095.dat" using 1:2 title "TC095", \
B095(x) w l lc rgb "blue" title "TC095 fit", \
"data/correlation_TC2.dat" using 1:2 title "TC2", \
B2(x) w l lc rgb "green" title "TC2 fit"

