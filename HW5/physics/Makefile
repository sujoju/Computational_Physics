all : lib 
lib : lib/libphysics.a

lib/%.o : src/%.c
	gcc -g -ansi -pedantic -std=gnu99 -Iinclude -I../common/include -c $< -o $@ -lgsl -lphysics

lib/libphysics.a : lib/projectiles.o \
	lib/sho.o lib/wave.o \
	lib/decay.o \
	lib/exp_for_GSL.o \
	lib/higgs_BG_gsl.o \
	lib/higgs_SIG_BGfixed_gsl.o \
	lib/higgs_SIG_BG2comp_gsl.o \
	lib/utils.o
	ar -r lib/libphysics.a $^

clean : 
	rm lib/*.a 
	rm lib/*.o
	
.PHONY : clean 

