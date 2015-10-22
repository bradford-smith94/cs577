/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 prealloc.c
 * 10/21/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "protect.h"

/* pre: takes in a void* ptr and a size_t size
 * post: changes the size of the memory block pointed to by ptr to size bytes
 *      plus guard-page protection
 * returns: a pointer to the allocated block of memory
 */
void* prealloc(void* ptr, size_t size)
{
    if (ptr == NULL)
        return pmalloc(size);
    else if (size == 0)
    {
        pfree(ptr);
        return NULL;
    }

    pfree(ptr);
    return pmalloc(size);
}
