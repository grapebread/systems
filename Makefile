all: main.o
	gcc -o switcheroo main.o

main.o: main.c
	gcc -c main.c