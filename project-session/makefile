EXEC=MLG_RPG
EXECCMD=exec
DBUGCMD=valgrind --leak-check=full

CD=cd
RM=/usr/bin/rm -rf
CP=/usr/bin/cp
MV=/usr/bin/mv
ZIP=/usr/bin/zip -r
ECHO=/usr/bin/echo
MKDIR=/usr/bin/mkdir -p

BINDIR=./bin
SRCDIR=./src

OBJECTS=$(SRCDIR)/main.o \
        $(SRCDIR)/Classe/Arme.o     $(SRCDIR)/Classe/Paysan.o \
        $(SRCDIR)/Classe/Prete.o    $(SRCDIR)/Classe/Illusionniste.o \
		$(SRCDIR)/Classe/Guerrier.o $(SRCDIR)/Classe/Magicien.o \
		$(SRCDIR)/Fonction/faccent.o

LINUX_CC=g++
LINUX_LD=g++
LINUX_CCFLAGS=-Wall -pedantic -std=c++11 -finput-charset=windows-1252
LINUX_LDFLAGS=

WIN32_CC=i686-w64-mingw32-g++
WIN32_LD=i686-w64-mingw32-g++
WIN32_LIBS_LOC=
WIN32_LIBS=
WIN32_CCFLAGS=-Wall -pedantic -std=c++11
WIN32_LDFLAGS=-static

ifndef $(TARGET)
	ifeq ($(TARGET), linux)
		CC=$(LINUX_CC)
		LD=$(LINUX_LD)
		CCFLAGS=$(LINUX_CCFLAGS)
		LDFLAGS=$(LINUX_LDFLAGS)
	else ifeq ($(TARGET), win32)
		CC=$(WIN32_CC)
		LD=$(WIN32_LD)
		CCFLAGS=$(WIN32_CCFLAGS)
		LDFLAGS=$(WIN32_LDFLAGS)
	else
		CC=$(LINUX_CC)
		LD=$(LINUX_LD)
		CCFLAGS=$(LINUX_CCFLAGS)
		LDFLAGS=$(LINUX_LDFLAGS)
	endif
endif

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(LD) -o $(BINDIR)/$(EXEC) $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

linux:
	make TARGET=linux

win32:
	make TARGET=win32
	@$(MV) $(BINDIR)/$(EXEC) $(BINDIR)/$(EXEC).exe

mkdir:
	@$(MKDIR) $(BINDIR)

zip:
	$(ZIP) $(EXEC).zip $(BINDIR)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(BINDIR)/*.dll
	$(RM) $(BINDIR)/$(EXEC)
	$(RM) $(BINDIR)/$(EXEC).exe
	$(RM) $(EXEC).zip
run:
	@$(CD) $(BINDIR); \
	$(EXECCMD) ./$(EXEC)
debug:
	@$(CD) $(BINDIR); \
	$(DBUGCMD) ./$(EXEC)
