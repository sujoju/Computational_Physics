#!/bin/sh 

./bin/assignment5_2_a.exe ./data/higgs.dat 60 >& log/higgs_BGonly.log

./bin/assignment5_2_b.exe ./data/higgs.dat 60 >& log/higgs_sig_bgfixed.log

./bin/assignment5_2_c.exe  ./data/higgs.dat 60 >& log/higgs_sig_bg2comp.log

gnuplot ./gnuplot/higgsfit_BGonly.plt  
gnuplot ./gnuplot/higgsfit_fixedBG.plt
gnuplot ./gnuplot/higgsfit_2compBG.plt  