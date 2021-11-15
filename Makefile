all: main.o
	gcc -o parse-args main.o

main.o: main.c
	gcc -c main.c

run:
	./parse-args

clean:
	@rm *.o *.exe* *.gch || true