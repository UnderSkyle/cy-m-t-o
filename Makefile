all: exec


main.o: main.c filter.h smallfunction.h
	gcc -c main.c -o main.o
	
exec: main.o
	gcc main.o -o exec

