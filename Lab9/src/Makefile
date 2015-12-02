# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 9
# 12/01/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

PRG=notavirus
AUTHOR=bsmith8
PROJECT=cs577-lab9
SRC=baseline.c #packing.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=-I../include
LIBPATH=
LDLIBS=
LDFLAGS+=

# Linux
# CC=gcc
# LD=ld

# Windows
CC=x86_64-w64-mingw32-gcc
LD=x86_64-w64-mingw32-ld

# implicit compiling rules:
# C complied with: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
CFLAGS+= $(INCLPATH)
CPPFLAGS+= #-pedantic-errors -Wall
DBFLGS= -g -DDEBUG

all: $(OBJ)
ifeq ($(CC),gcc)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG)
else
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG:=.exe)
endif

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PRG)
	$(RM) $(PRG:=.exe)

re: fclean all

tar: fclean
	tar -cvzf ../../$(AUTHOR)_$(PROJECT).tar.gz ./*

