# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 2
# 09/24/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

PRG=cracker
AUTHOR=bsmith8
PROJECT=cs577-lab2
SRC=main.cpp printError.cpp printDebug.cpp cleanExit.cpp parseInput.cpp \
	parseLine.cpp getMd5.cpp bruteForce.cpp dictionary.cpp heuristic.cpp \
	allDone.cpp writeOutput.cpp checkAllPasswords.cpp
OBJ=$(SRC:.cpp=.o)
CXX=clang++
RM=rm -f
INCLPATH=-I../include
LIBPATH=
LDLIBS= -lcrypto
LDFLAGS+=
# implicit compiling rules:
# C++ complied with: `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)`
CXXFLAGS+= -std=c++11 $(INCLPATH)
CPPFLAGS+= -pedantic-errors -Wall
DBFLGS= -g -DDEBUG

all: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG)

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) ../nosalt_out.txt
	$(RM) ../salt_out.txt
	$(RM) $(PRG)

re: fclean all

test: debug
	./cracker ../passwords_nosalt.txt ../nosalt_out.txt 120
	./cracker ../passwords_salt.txt ../salt_out.txt 120 id14

tar: fclean
	tar -cvzf ../../$(AUTHOR)_$(PROJECT).tar.gz ../*

