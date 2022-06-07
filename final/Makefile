

all : bin/final_1.exe

bin/%.exe : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude -IIsing/include  -INeural/include $< -o  $@ -lm -LIsing/lib -lIsing  -LNeural/lib -lNeural




clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~
	rm -f scripts/*.sh~
	#rm -f data/*.dat
	rm -f img/*.png
	#make -C physics clean
	#make -C ode clean

.PHONY : clean 
#.PHONY : clean ode physics

