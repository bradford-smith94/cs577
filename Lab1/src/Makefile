# Bradford Smith (bsmith8)
# Makefile for lab1
# 09/18/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

NAME=bsmith8
ASSIGNMENT=cs577-lab1
PROXY=proxy
SRC=main.c getPortFromArgs.c printFormatting.c httpConnect.c sslServerInit.c \
	sslCerts.c connectHost.c
OBJ=$(SRC:.c=.o)
CC=gcc
RM=rm -f
INCLPATH=-I../include -I/usr/include/openssl
LDLIBS+= -lssl -lcrypto
CPPFLAGS+= -Wall
CFLAGS+= $(INCLPATH)
DBFLGS= -g -DDEBUG
OPENSSL= ../bin/openssl

all: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PROXY)

debug: fclean
debug: CFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PROXY)
	$(RM) *.pem

re: fclean all

# this sets up for testing
test-gen:
	$(OPENSSL) genrsa -out key.pem 2048
	$(OPENSSL) req -new -x509 -key key.pem -out cert.pem -days 1095

test-server:
	$(OPENSSL) s_server -cert cert.pem -key key.pem -accept 8900

test-client:
	$(OPENSSL) s_client -proxy 127.0.0.1:8000 -connect 127.0.0.1:8900 -state \
		-verify 1 -CAfile cert.pem

tar: fclean
	tar -cvzf ../$(NAME)_$(ASSIGNMENT).tar.gz ../include/proxy.h ../src ../report.txt
