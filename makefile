all: main.o randfile.o
	gcc -o program main.o randfile.o

main.o: main.c randfile.c
	gcc -c main.c

randfile.o: randfile.c randheader.h
	gcc -c randfile.c

randheader.o: randheader.c randheader.h
	gcc -c randheader.c

run:
	./program

clean:
	rm *.o
	rm *~
