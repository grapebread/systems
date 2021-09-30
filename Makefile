all: main.o
	gcc -o pointers main.o

main.o: main.c
	gcc -c main.c

clean:
	rm *.o
	rm *~

run:
	./pointers.exe