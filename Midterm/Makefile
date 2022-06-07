all : bin/midterm_1.exe bin/midterm_2.exe bin/midterm_2_fft.exe
#bin/compiler_error.exe 

# don't include lib targets for lib distribution ...
#ode :  ode
#	cd ode && make lib && cd - 
#physics : 
#	cd physics && make lib && cd - 
#main_%.exe : src/main_%.c ode physics 

bin/midterm_%.exe : src/midterm_%.c
	gcc -O2 -g -ansi -pedantic -std=gnu99 -Icommon/include -Iphysics/include -I ode/include $< -o $@ -Lode/lib -Lphysics/lib -lfftw3 -lm -lphysics -lODE
	
cleanbin : 
	rm ./bin/*.exe

cleandata: 
	rm ./data/*.dat

cleanimg: 
	rm ./img/*.png
	rm ./img/*.gif

.PHONY :  clean

