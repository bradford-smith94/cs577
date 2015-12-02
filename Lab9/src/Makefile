# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 9
# 12/02/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

AUTHOR=bsmith8
PROJECT=cs577-lab9
C=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=-I../include
LIBPATH=
LDLIBS=
LDFLAGS+=

# Linux (as default)
# CC=gcc
# LD=ld

# Windows (as default)
CC=x86_64-w64-mingw32-gcc
LD=x86_64-w64-mingw32-ld

# implicit compiling rules:
# C complied with: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
CFLAGS+= $(INCLPATH)
CPPFLAGS+= #-pedantic-errors -Wall

# build all programs following default
all: baseline packing memory cpu name sleep key

# force linux and build all
linux: CC=gcc
linux: LD=ld
linux: all

# force windows and build all
windows: CC=x86_64-w64-mingw32-gcc
windows: LD=x86_64-w64-mingw32-ld
windows: all

# build part 1
baseline: baseline.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 2
packing: packing.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 3
memory: memory.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 4
cpu: cpu.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 5
name: name.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 6
sleep: sleep.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# build part 7
key: key.o
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=)
else
	$(CC) $(LDFLAGS) $(<) $(LDLIBS) -o $(<:.o=.exe)
endif

# remove object files
clean:
	$(RM) *.o

# remove executables
fclean: clean
	$(RM) $(C:.c=)
	$(RM) $(C:.c=.exe)

# full clean and rebuild following default
re: fclean all

# make executables, clean objects and tar.gz it all
tar: all clean
	tar -cvzf ../../$(AUTHOR)_$(PROJECT).tar.gz ../*

