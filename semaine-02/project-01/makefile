CC=g++
LD=g++

CCFLAGS=-W -Wall -pedantic
LDFLAGS=

EXEC=main
BINDIR=/usr/bin
SRCDIR=src

OBJECTS=$(SRCDIR)/main.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o bin/$(EXEC) $(OBJECTS) $(LDFLAGS)

main.o:
	$(CC) -o $(SRCDIR)/main.o $(SRCDIR)/main.cpp $(CCFLAGS)

clean:
	rm -rf $(OBJECTS)

run:
	exec ./bin/$(EXEC)

install:
	cp bin/$(EXEC) $(BINDIR)/$(EXEC)

uninstall:
	rm $(BINDIR)/$(EXEC)
