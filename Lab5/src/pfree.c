/* Bradford Smith (bsmith8)
 * CS 577 Lab 5  pfree.c
 * 10/22/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "protect.h"

/* pre: takes in a void* ptr
 * post: deallocates the memory space pointed to by ptr and its guard-page
 */
void pfree(void* ptr)
{
    struct s_meta meta;

    /* error check */
    if (ptr == NULL)
        return;

    /* get the metadata struct, it was left just before the buffer pointer */
    meta = *((struct s_meta*)((unsigned long)ptr - sizeof(meta)));

#ifdef DEBUG
    printf("[DEBUG]\t[pfree]\tfreeing size: %lu\n\tfrom: %lu\n\tbuflen: %lu\n",
            (unsigned long)meta.len,
            (unsigned long)meta.ptr,
            (unsigned long)meta.buflen);
    fflush(stdout);
#endif

    munmap(meta.ptr, meta.len);

#ifdef DEBUG
    printf("[DEBUG]\t[pfree]\tleaving...\n");
    fflush(stdout);
#endif
}
