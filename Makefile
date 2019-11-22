CC=gcc
CFLAGS=--std=c99 -O2 -Wextra
RUNC=$(CC) $(CFLAGS)

SOURCES=$(wildcard src/**/*.c)
OBJECTS=$(wildcard bin/**/*.o)
EXECUTABLE=bench

bench: src/main.c $(OBJECTS)
	$(RUNC) -o bin/$(EXECUTABLE) src/main.c

$(OBJECTS): $(SOURCES)
	$(RUNC) -c $< -o $@

clean:
	rm bin/$(EXECUTABLE) bin/*.o