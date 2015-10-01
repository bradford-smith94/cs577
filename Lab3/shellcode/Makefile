CFLAGS=-O0 #-mpreferred-stack-boundary=2 
TARGETS=hello hello.sc
CC=gcc
LD=ld

all: $(TARGETS)

hello: hello.o
	$(LD) -o $@ $<

%.sc: %.o
	 objcopy -O binary --only-section=.text $< $@

%.o: %.S
	$(CC) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf $(TARGETS) *.o
