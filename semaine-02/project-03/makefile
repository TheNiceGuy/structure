CC=g++
LD=g++
DB=valgrind

CCFLAGS=-W -Wall -pedantic
LDFLAGS=

EXEC=main
BINDIR=/usr/bin
SRCDIR=src

OBJECTS=$(SRCDIR)/main.o $(SRCDIR)/random.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o bin/$(EXEC) $(OBJECTS) $(LDFLAGS)

main.o:
	$(CC) -o $(SRCDIR)/main.o $(SRCDIR)/main.cpp $(CCFLAGS)

random.o:
	$(CC) -o $(SRCDIR)/random.o $(SRCDIR)/random.cpp $(CCFLAGS)

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
