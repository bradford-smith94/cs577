# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 5
# 10/19/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

LIB=../lib/libprotect.so
OVERRIDE=../lib/liboverride.so
AUTHOR=bsmith8
PROJECT=cs577-lab5
LIBSRC=pmalloc.c pfree.c pcalloc.c prealloc.c pmemalign.c
OVRSRC=malloc.c free.c calloc.c realloc.c memalign.c
LIBOBJ=$(LIBSRC:.c=.o)
OVROBJ=$(OVRSRC:.c=.o)
CC=gcc
RM=rm -f
INCLPATH=-I../include
LIBPATH=-L../lib
LDLIBS=
OVRLDLIBS=-lprotect
LDFLAGS+= $(LIBPATH) -shared
# implicit compiling rules:
# C complied with: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
CFLAGS+= $(INCLPATH) -fPIC
CPPFLAGS+= -pedantic-errors -Wall
CXXFLAGS+=
DBFLGS= -g -DDEBUG

all: $(LIB) $(OVERRIDE) testmain

$(LIB): $(LIBOBJ)
	mkdir -p ../lib
	$(CC) $(LDFLAGS) $(LIBOBJ) $(LDLIBS) -o $(LIB)

$(OVERRIDE): $(OVROBJ)
	mkdir -p ../lib
	$(CC) $(LDFLAGS) $(OVROBJ) $(OVRLDLIBS) -o $(OVERRIDE)

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

testmain: main.o
	$(CC) main.o -o test

test: debug
	LD_LIBRARY_PATH=../lib LD_PRELOAD=$(OVERRIDE) ./test

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(LIB)
	$(RM) $(OVERRIDE)
	$(RM) test

re: fclean all

tar: fclean
	tar -cvzf ../../$(AUTHOR)_$(PROJECT).tar.gz ../*

