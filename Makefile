all: exec


main.o: main.c filter.h smallfunction.h struct.h
	gcc -o main.c -o main.o
	
struct.o: struct.h
	gcc -o struch.h -o struct.o
	
shell.o: shell.sh
	gcc -o shell.sh -o shell.o
	
AVL.o: AVL.c
	gcc -o AVL.c -o AVL.o
	
ABR.o: ABR.c
	gcc -o ABR.c -o ABR.o

trirapide.o: trirapide.c
	gcc -o trirapide.c -o trirapide.o
	
exec: main.o shell.o AVL.o ABR.o trirapide.o struct.o
	gcc main.o shell.o ABR.o AVL.o trirapide.o struct.o -o exec

