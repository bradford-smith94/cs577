/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 prealloc.c
 * 10/22/2015
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
    struct s_meta meta;
    void* newbuf;
    size_t minsize;

    /* error check */
    if (ptr == NULL)
        return pmalloc(size);
    else if (size == 0)
    {
        pfree(ptr);
        return NULL;
    }

    /* get the matadata struct, it was left just before the buffer pointer */
    meta = *((struct s_meta*)((unsigned long)ptr - sizeof(meta)));

    /* if the requested size is the same as what they have, just give it back */
    if (meta.buflen == size)
        return ptr;
    else if (meta.buflen > size) /* if requested size is less than what they had */
        minsize = size;
    else
        minsize = meta.buflen;

#ifdef DEBUG
    printf("[DEBUG]\t[prealloc]\tcalling pmalloc with: %lu\n",
            (unsigned long)size);
    fflush(stdout);
#endif

    /* allocate a new buffer */
    newbuf = pmalloc(size);

#ifdef DEBUG
    printf("[DEBUG]\t[prealloc]\tdoing memcpy...\n");
    fflush(stdout);
#endif

    /* copy into the new buffer form the old buffer with size of whichever was
     * smaller */
    memcpy(newbuf, ptr, minsize);

#ifdef DEBUG
    printf("[DEBUG]\t[prealloc]\tcalling pfree...\n");
    fflush(stdout);
#endif

    /* free the old buffer */
    pfree(ptr);

    return newbuf;
}
