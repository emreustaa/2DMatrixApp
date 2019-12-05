all:makefile run

makefile: main.o matrixOps.o
	gcc main.o matrixOps.o -o makefile

main.o: main.c
	gcc -c main.c

matrixOps.o: matrixOps.c matrixOps.h
	gcc -c matrixOps.c

clean:
	del *.o makefile.exe

run:
	makefile.exe