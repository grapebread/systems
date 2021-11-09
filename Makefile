all: main.o pop_entry.o
	gcc -o structrw main.o pop_entry.o

main.o: main.c
	gcc -c main.c

pop_entry.o: pop_entry.c pop_entry.h
	gcc -c pop_entry.c

run:
	./structrw

run_csv:
	./structrw -read_csv

run_data:
	./structrw -read_data

run_add:
	./structrw -add_data

run_update:
	./structrw -update_data

clean:
	@rm -f *.o *.exe *.gch *.bin *.stackdump || true