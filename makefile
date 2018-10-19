all: linkedlist.o driver.o lib.o
	gcc driver.o linkedlist.o lib.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

lib.o: lib.c lib.h linkedlist.h
	gcc -c lib.c

driver.o: driver.c lib.h
	gcc -c driver.c

run:
	./a.out

clean:
	rm *.o
debug:
	gcc -g lib.c linkedlist.c driver.c
