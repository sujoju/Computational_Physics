frandomization=0.0
fdamage=0.0

testp="./mystery/001.dat"
inputp=("./character_groups/001/1.dat" "./character_groups/001/E.dat" "./character_groups/001/P.dat" "./character_groups/001/T.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} > output

testp="./mystery/002.dat"
inputp=("./character_groups/002/7.dat" "./character_groups/002/G.dat" "./character_groups/002/H.dat" "./character_groups/002/X.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output

testp="./mystery/003.dat"
inputp=("./character_groups/003/0.dat" "./character_groups/003/A.dat" "./character_groups/003/T.dat" "./character_groups/003/Y.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output

testp="./mystery/004.dat"
inputp=("./character_groups/004/M.dat" "./character_groups/004/Q.dat" "./character_groups/004/S.dat" "./character_groups/004/U.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output

testp="./mystery/005.dat"
inputp=("./character_groups/005/3.dat" "./character_groups/005/9.dat" "./character_groups/005/B.dat" "./character_groups/005/Z.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output

testp="./mystery/006.dat"
inputp=("./character_groups/006/5.dat" "./character_groups/006/I.dat" "./character_groups/006/L.dat" "./character_groups/006/Q.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output

testp="./mystery/007.dat"
inputp=("./character_groups/007/2.dat" "./character_groups/007/B.dat" "./character_groups/007/C.dat" "./character_groups/007/N.dat")

./bin/final_1.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} >> output
