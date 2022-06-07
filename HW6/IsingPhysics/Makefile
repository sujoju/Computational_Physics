

all : lib/libIsingPhysics.a

lib/libIsingPhysics.a : obj/magnetism.o
	ar -r $@ $^

# add -DVERBOSE to plot a circle trial ...
obj/%.o : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude  -I../Ising/include $< -c -o  $@ 


clean : 
	rm -f *~
	rm -f lib/*.a
	rm -f obj/*.o 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~



