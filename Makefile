all: main.o
	gcc -o construction main.o

main.o: main.c
	gcc -c main.c

run:
	./construction

clean:
	rm *.o *.exe