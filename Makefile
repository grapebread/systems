all: main.o dex.o
	gcc -o list main.o dex.o

main.o: main.c
	gcc -c main.c

dex.o: dex.c dex.h
	gcc -c dex.c dex.h

clean:
	rm *.o *.exe

run:
	@./list