all : lib
lib : lib/libODE.a

lib/%.o : src/%.c
	gcc -g -ansi -pedantic -std=gnu99 -Iinclude -I../common/include -c $< -o $@

lib/libODE.a : lib/euler.o lib/rkO2.o lib/rkO4.o
	ar -r lib/libODE.a $^

clean : 
	rm lib/*.a 
	rm lib/*.o

.PHONY : clean 
