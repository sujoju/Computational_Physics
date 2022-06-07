

all : lib/libNeural.a

lib/libNeural.a : obj/pattern.o obj/Jmatrix.o obj/neural.o 
	ar -r $@ $^

obj/%.o : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude -I../Ising/include  $< -c -o  $@ 


clean : 
	rm -f *~
	rm -f lib/*.a
	rm -f obj/*.o 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~



