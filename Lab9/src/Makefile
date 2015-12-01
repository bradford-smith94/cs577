# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 9
# 12/01/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

PRG=notavirus
AUTHOR=bsmith8
PROJECT=cs577-lab9
SRC=baseline.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=-I../include
LIBPATH=
LDLIBS=
LDFLAGS+=
# implicit compiling rules:
# C complied with: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
CFLAGS+= $(INCLPATH) #-std=c99
CPPFLAGS+= #-pedantic-errors -Wall
DBFLGS= -g -DDEBUG

all: linux

linux: CC=gcc
linux: LD=ld
linux: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG)

win: CC=x86_64-w64-mingw32-gcc
win: LD=x86_64-w64-mingw32-ld
win: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG:=.exe)

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

