all: exec


main.o: main.c filter.h smallfunction.h
	gcc -o main.c -o main.o
	
shell.o: shell.sh
	gcc -o shell.sh -o shell.o
	
AVL.o: AVL.c
	gcc -o AVL.c -o AVL.o
	
ABR.o: ABR.c
	gcc -o ABR.c -o ABR.o

trirapide.o: trirapide.c
	gcc -o trirapide.c -o trirapide.o
	
exec: main.o shell.o AVL.o ABR.o trirapide.o
	gcc main.o shell.o ABR.o AVL.o trirapide.o -o exec

