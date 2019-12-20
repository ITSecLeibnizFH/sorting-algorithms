CC=gcc
CFLAGS=--std=c99 -O2
DEBUGFLAGS=--std=c99 -g
RUNC=$(CC) $(CFLAGS)
RUNDEBUG=$(CC) $(DEBUGFLAGS)

ALL_SOURCES=$(wildcard src/**/*.c)

# I thought we'd need this to not compile the template files, but it seems to work fine without.
# If in doubt, uncomment the next two lines.
#EXCLUDES=$(shell cat ./.makeexclude)
#SOURCES=$(filter-out $(EXCLUDES),$(ALL_SOURCES))

SOURCES=$(ALL_SOURCES)
OBJECTS=$(wildcard bin/**/*.o)
EXECUTABLE=bench

debug: src/main.c $(OBJECTS)
	$(RUNDEBUG) -o bin/$(EXECUTABLE) src/main.c
	cp testdata/*.txt bin/

release: src/main.c $(OBJECTS)
	$(RUNC) -o bin/$(EXECUTABLE) src/main.c
	cp testdata/*.txt bin/

run: bin/bench
	./bin/bench

$(OBJECTS): $(SOURCES)
	$(RUNC) -c $< -o $@

clean:
	rm -f bin/$(EXECUTABLE) bin/*.o
	rm -f bin/*.txt