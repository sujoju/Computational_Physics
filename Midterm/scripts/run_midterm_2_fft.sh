#!/bin/sh

# wave data generated with run_beat.sh

# run the ffts
./bin/midterm_2_fft.exe 1 > ./data/fft_beat_k1.dat
./bin/midterm_2_fft.exe 2 > ./data/fft_beat_k2.dat
# plot the output with beat_k1k2.plt ...

./bin/midterm_2_fft.exe 3 > ./data/fft_beat_sum.dat
# plot the output with beat_sum.plt ...

./bin/midterm_2_fft.exe 4 > ./data/fft_beat_k3.dat
# plot the output with beat_sum.plt ...
