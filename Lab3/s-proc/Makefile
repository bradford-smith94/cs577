CFLAGS=-O2
TARGETS=s-proc
CC=gcc

all: $(TARGETS)


s-proc: s-proc.o
	$(CC) -z execstack $(LDFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf $(TARGETS) *.o
