
all : bin/assignment6_1.exe \
bin/assignment6_2.exe \
bin/assignment6_3.exe \
bin/assignment6_4.exe \
bin/assignment6_4_fit.exe \
bin/assignment6_5.exe 

bin/%.exe : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -IIsing/include  -IIsingPhysics/include $< -o  $@ -LIsing/lib -LIsingPhysics/lib -lm -lIsing -lIsingPhysics

bin/assignment6_4_fit.exe : src/assignment6_4_fit.c
	gcc -g -ansi -std=gnu99 -pedantic -Ifit/include $^ -o $@ -Lfit/lib -lm -lfit -lgsl -lgslcblas

clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~
	rm -f scripts/*.sh~
	rm -f gnuplot/*.plt~
	rm -f log/*.log~
	rm -f slurm/*~
	#rm -f data/*.dat
	#rm -f img/*.png
	#make -C physics clean
	#make -C ode clean

.PHONY : clean 
#.PHONY : clean ode physics

