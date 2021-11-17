all: main.o
	gcc -o forkin main.o

main.o: main.c
	gcc -c main.c

run:
	./forkin

clean:
	@rm *.o *.exe *.gch || true