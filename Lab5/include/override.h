/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 override.h
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#ifndef _OVERRIDE_H_
#define _OVERRIDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* This is the header that enables overriding of libc functions
 */
extern void* pmalloc(size_t);
extern void  pfree(void*);
extern void* pcalloc(size_t, size_t);
extern void* prealloc(void*, size_t);
extern void* pmemalign(size_t, size_t);

void*   malloc(size_t);
void    free(void*);
void*   calloc(size_t, size_t);
void*   realloc(void*, size_t);
void*   memalign(size_t, size_t);

#endif /* _OVERRIDE_H_ */
