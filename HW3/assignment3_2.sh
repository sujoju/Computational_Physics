# reproduce figure 2.5
vi=700
angles="20 30 40 45 50 60 70";
pi=$(echo "scale=10; 4*a(1)" | bc -l) 

for a in `echo $angles`; do
    vx=$(echo "scale=10; $vi*c($a*$pi/180)" | bc -l); 
    vy=$(echo "scale=10; $vi*s($a*$pi/180)" | bc -l); 
    ./bin/assignment3_2.exe $vx $vy 0 > data/drag_${a}.dat
    ./bin/assignment3_2.exe $vx $vy 1 > data/drag_adiabatic_${a}.dat
done