#!/bin/sh

./scripts/run_assignment4_1.sh 200 1.5
./scripts/run_assignment4_1.sh 200 4.0
./scripts/run_assignment4_2.sh
./scripts/run_assignment4_2_fft.sh
./scripts/run_assignment4_2_offcenter.sh
./scripts/run_assignment4_2_fft_offcenter.sh

gnuplot ./gnuplot/fft_pulse.plt
gnuplot ./gnuplot/fft_power.plt