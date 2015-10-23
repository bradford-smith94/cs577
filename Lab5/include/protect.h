/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 protect.h
 * 10/21/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#ifndef _PROTECT_H_
#define _PROTECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/mman.h>

/* define a 4KB memory page size */
#define PAGE_SIZE 4096

/* define the size of the alignment we desire, this will return either 4 or 8 */
#define ALIGNMENT sizeof(void*)

/* struct for the allocated space metadata */
struct s_meta
{
    /* start address of the block, including padding and metadata */
    void* ptr;
    /* total length of the block including padding, metadata and guard-page */
    size_t len;
    /* length of the user buffer */
    size_t buflen;
};

/* This is the header file that defines the protected versions of libc functions
 */
void*   pmalloc(size_t);
void    pfree(void*);
void*   pcalloc(size_t, size_t);
void*   prealloc(void*, size_t);
void*   pmemalign(size_t, size_t);

#endif /* _PROTECT_H_ */
