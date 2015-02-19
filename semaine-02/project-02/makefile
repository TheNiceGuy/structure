CC=g++
LD=g++
DB=valgrind

CCFLAGS=-W -Wall -pedantic
LDFLAGS=

EXEC=main
BINDIR=/usr/bin
SRCDIR=src

OBJECTS=$(SRCDIR)/function.o $(SRCDIR)/main.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o bin/$(EXEC) $(OBJECTS) $(LDFLAGS)

function.o:
	$(CC) -o $(SRCDIR)/function.o $(SRCDIR)/function.cpp $(CCFLAGS)

main.o:
	$(CC) -o $(SRCDIR)/main.o $(SRCDIR)/main.cpp $(CCFLAGS)

mkdir:
	@mkdir -p bin

clean:
	rm -rf $(OBJECTS)

run:
	exec bin/$(EXEC)

debug:
	$(DB) bin/$(EXEC)

install:
	cp bin/$(EXEC) $(BINDIR)/$(EXEC)

uninstall:
	rm $(BINDIR)/$(EXEC)
