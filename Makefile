CC=gcc
CFLAGS=-O2
RUNC=$(CC) $(CFLAGS)

all: main
default: main
main: src/main.c util.o
	$(RUNC) -o bin/main src/main.c

util.o: src/util/*.c src/util/*.h
	$(RUNC) -c src/util/timer.c -o bin/util.o

clean:
	rm bin/main bin/*.o