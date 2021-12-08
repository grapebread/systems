all: main.o
	gcc -o plumbing main.o

main.o: main.c
	gcc -c main.c

run:
	./plumbing

clean:
	@rm *.o *.exe *.gch || true