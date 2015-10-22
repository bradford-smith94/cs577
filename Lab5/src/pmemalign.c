/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 pmemalign.c
 * 10/21/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "protect.h"

/* pre: takes in a size_t boundary and a size_t size
 * post: returns a pointer to an allocated block of memory with a guard page,
 *      the address is a multiple of boundary
 * returns: a pointer to the allocated block of memory or NULL on failure
 */
void* pmemalign(size_t boundary, size_t size)
{
    struct s_meta meta;
    size_t padding;
    size_t* guardPage;
    size_t* buffer;

    /* error check */
    if (size == 0)
        return NULL;

    /* loop until size is a multiple of boundary -- note the semicolon here */
    for (;size % boundary != 0; size += 1);

    /* get the ammount of padding before the buffer (accounts for metadata) */
    padding = PAGE_SIZE - ((size + sizeof(meta)) % PAGE_SIZE);
    padding += sizeof(meta);

    guardPage = mmap(NULL,
            PAGE_SIZE,
            PROT_NONE,
            MAP_SHARED | MAP_ANONYMOUS,
            -1,
            0);
    buffer = mmap(guardPage - (size + padding),
            (size + padding),
            PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS,
            -1,
            0);

    meta.len = size + padding + PAGE_SIZE;
    memcpy(&buffer[padding - sizeof(meta)], &meta, sizeof(meta));

    return (void*)&buffer[padding];
}
