a.out: GDAT.o main.o
	gcc GDAT.o main.o -lm
GDAT.o: GDAT.c GDAT.h
	gcc -c GDAT.c
main.o: main.c GDAT.h
	gcc -c main.c -lm

-std=c++11