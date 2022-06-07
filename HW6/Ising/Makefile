

all : lib/libIsing.a

lib/libIsing.a : obj/IsingLattice2D.o
	ar -r $@ $^

# add -DVERBOSE to plot a circle trial ...
obj/%.o : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude  $< -c -o  $@ 


clean : 
	rm -f *~
	rm -f lib/*.a
	rm -f obj/*.o 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~



