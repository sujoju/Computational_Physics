all : lib 
lib : lib/libphysics.a

lib/%.o : src/%.c
	gcc -O2 -g -ansi -pedantic -std=gnu99 -Iinclude -I../common/include -c $< -o $@

lib/libphysics.a : lib/projectiles.o lib/sho.o lib/wave.o lib/decay.o
	ar -r lib/libphysics.a $^

clean : 
	rm lib/*.a 
	rm lib/*.o
	
.PHONY : clean 

