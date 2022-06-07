set terminal png size 1500,500
set output "img/midterm_2_fft_k1k2.png"

#change k's accordingly
k1 = 4
k2 = 4.4
f1 = 300*k1
f2 = 300*k2

# and n if needed ..
N = 800

set multiplot layout 2,1 

title1 = sprintf("f: %.0f Hz", f1)
title2 = sprintf("f: %.0f Hz", f2)

set xrange[0:0.0066]
p "data/fft_beat_k1.dat" u 4:6 w l title title1, "data/fft_beat_k2.dat" u 4:6 w l title title2

title_re_k1 = sprintf("Re, f: %.0f Hz", f1)
title_im_k1 = sprintf("Im, f: %.0f Hz", f1)
title_re_k2 = sprintf("Re, f: %.0f Hz", f2)
title_im_k2 = sprintf("Im, f: %.0f Hz", f2)

set xrange[1000:2000]
set arrow from f1, graph 0 to f1, graph 1 nohead 
set arrow from f2, graph 0 to f2, graph 1 nohead 
p "data/fft_beat_k1.dat" u ($2/(N*0.000033)):(sqrt($8*$8)) w l title title_re_k1, "data/fft_beat_k1.dat" u ($2/(N*0.000033)):(sqrt($10*$10)) w l title title_im_k1 , "data/fft_beat_k2.dat" u ($2/(N*0.000033)):(sqrt($8*$8)) w l title title_re_k2, "data/fft_beat_k2.dat" u ($2/(N*0.000033)):(sqrt($10*$10)) w l title title_im_k2



