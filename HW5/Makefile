all : bin/assignment5_1.exe \
bin/assignment5_2_a.exe \
bin/assignment5_2_b.exe \
bin/assignment5_2_c.exe
#bin/compiler_error.exe 

bin/assignment5_1.exe : src/assignment5_1.c
	gcc -g -ansi -pedantic -std=gnu99 -Icommon/include -Iphysics/include -Iode/include $< -o $@ -Lode/lib -Lphysics/lib -lm -lphysics -lODE -O2

bin/assignment5_2_%.exe : src/assignment5_2_%.c
	gcc -g -ansi -pedantic -std=gnu99 -Icommon/include -Iphysics/include $< -o $@ -Lphysics/lib -lm -lphysics -lgsl -lgslcblas

cleanbin : 
	rm ./bin/*.exe

cleandata: 
	rm ./data/bifurcation.dat

cleanimg: 
	rm ./img/*.png

cleanlog: 
	rm ./log/*.log

.PHONY :  clean

