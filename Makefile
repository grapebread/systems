all: main.o mystring.o
	gcc -o string main.o mystring.o

main.o: main.c mystring.h
	gcc -c main.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

run:
	./string

clean:
	rm *.o *.exe