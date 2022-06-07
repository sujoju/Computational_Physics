all : bin/assignment3_2.exe bin/assignment3_3.exe bin/assignment3_4.exe
#bin/compiler_error.exe 

# don't include lib targets for lib distribution ...
#ode :  ode
#	cd ode && make lib && cd - 
#physics : 
#	cd physics && make lib && cd - 
#main_%.exe : src/main_%.c ode physics 

bin/assignment3_%.exe : src/assignment3_%.c 
	gcc -g -ansi -pedantic -Icommon/include -Iphysics/include -I ode/include $< -o $@ -Lode/lib -Lphysics/lib -lm -lphysics -lODE

clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~
	make -C physics clean
	make -C ode clean

.PHONY :  clean

