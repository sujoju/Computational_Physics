all : lib 
lib : lib/libphysics.a

lib/%.o : src/%.c
	gcc -g -ansi -pedantic -std=gnu99 -Iinclude -I../common/include -c $< -o $@

lib/libphysics.a : lib/projectiles.o lib/sho.o
	ar -r lib/libphysics.a $^

.PHONY : clean 

