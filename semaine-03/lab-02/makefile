CC=g++
LD=g++

CCFLAGS=-W -Wall -pedantic
LDFLAGS=

EXEC=main
BINDIR=/usr/bin
SRCDIR=src

OBJECTS=$(SRCDIR)/main.o $(SRCDIR)/jeuDevine.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o bin/$(EXEC) $(OBJECTS) $(LDFLAGS)

main.o:
	$(CC) -o $(SRCDIR)/main.o $(SRCDIR)/main.cpp $(CCFLAGS)

jeuDevine.o:
	$(CC) -o $(SRCDIR)/jeuDevine.o $(SRCDIR)/jeuDevine.cpp $(CCFLAGS)

clean:
	rm -rf $(OBJECTS)

run:
	exec bin/$(EXEC)

install:
	cp bin/$(EXEC) $(BINDIR)/$(EXEC)

uninstall:
	rm $(BINDIR)/$(EXEC)
