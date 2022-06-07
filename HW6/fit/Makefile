all : lib 
lib : lib/libfit.a

obj/%.o : src/%.c
	gcc -g -ansi -pedantic -std=gnu99 -Iinclude -c $< -o $@ -lgsl

lib/libfit.a : obj/exp_for_GSL.o obj/utils.o
	ar -r lib/libfit.a $^

clean : 
	rm -f *~
	rm -f lib/*.a
	rm -f obj/*.o 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~
	
.PHONY : clean 

