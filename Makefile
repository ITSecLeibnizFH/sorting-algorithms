CC=gcc
CFLAGS=--std=c99 -O2
RUNC=$(CC) $(CFLAGS)

all: main
default: main
main: src/main.c timer.o load_testdata.o
	$(RUNC) -o bin/main src/main.c

timer.o: src/util/timer.h src/util/timer.c
	$(RUNC) -c src/util/timer.c -o bin/timer.o

load_testdata.o: src/util/load_testdata.h src/util/load_testdata.c
	$(RUNC) -c src/util/load_testdata.c -o bin/load_testdata.o

clean:
	rm bin/main bin/*.o