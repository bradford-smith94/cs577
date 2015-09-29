#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 256
#define DELIM ":"

struct block {
	struct block *next_block;
	char buf[BUFSIZE];
	void (*fptr)(const char *);
};

static struct block *last_block = NULL;


void print_normal(const char *str)
{
	while (*str != '\0')
		putc(*str++, stdout);
	putc('\n', stdout);
	fflush(stdout);
}

void print_lowercase(const char *str)
{
	while (*str != '\0')
		putc(tolower(*str++), stdout);
	putc('\n', stdout);
	fflush(stdout);
}

void process_blocks(void)
{
	struct block *i;

	for (i = last_block; i; i = i->next_block) {
		printf("Block:\n");
		i->fptr(i->buf);
	}
}

void add_block(char *str)
{
	struct block *blk;

	if (!(blk = (struct block *)malloc(sizeof(struct block)))) {
		perror("cannot allocate memory for block");
		exit (1);
	}

	if (str[0] == 'L') {
		blk->fptr = print_lowercase;
		str++;
	} else
		blk->fptr = print_normal;

	/* Oops! Vulnerable Code */
	strcpy(blk->buf, str);

	blk->next_block = last_block;
	last_block = blk;
	//printf("add block: %s\n", str);
}

int main(int argc, char* argv[]) 
{
	char mybuf[4096], *str;

	while (fread(mybuf, sizeof(mybuf), 1, stdin) >= 0) {
		str = strtok(mybuf, DELIM);
		while (str) {
			add_block(str);
			str = strtok(NULL, DELIM);
		}
		if (feof(stdin)) 
			break;
	}

	process_blocks();

	return 0;
}
