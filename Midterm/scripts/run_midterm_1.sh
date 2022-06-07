
xmaxi=100
tsteps="0.05 0.01 0.005 0.001 0.0005 0.0001"

# run once to get error
for t in ${tsteps[*]}; do
    xmax=`echo "$xmaxi*0.05/$t" | bc`
    ./bin/midterm_1.exe $xmax $t 0 > ./data/decay_euler_tstep_${t}.dat
    ./bin/midterm_1.exe $xmax $t 1  > ./data/decay_rkO2_tstep_${t}.dat
    ./bin/midterm_1.exe $xmax $t 2  > ./data/decay_rkO4_tstep_${t}.dat
done 

rm ./data/decay_*_perf.dat
# run again to get perf
for t in ${tsteps[*]}; do
    xmax=`echo "$xmaxi*0.05/$t" | bc`

    perf stat ./bin/midterm_1.exe $xmax $t 0 quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1perf}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_euler_tstep_${t}.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_euler_perf.dat

    perf stat ./bin/midterm_1.exe $xmax $t 1 quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_rkO2_tstep_${t}.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_rkO2_perf.dat

    perf stat ./bin/midterm_1.exe $xmax $t 2 quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_rkO4_tstep_${t}.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_rkO4_perf.dat

done 
