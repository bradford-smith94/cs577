/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 pcalloc.c
 * 10/22/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "protect.h"

/* pre: takes in a size_t nmemb and a size_t size
 * post: allocates memory for an array of nmemb elements of size bytes each and
 *      a guard-page
 * returns: a pointer to the allocated memory or NULL if either nmemb or size is
 *      equal to zero
 */
void* pcalloc(size_t nmemb, size_t size)
{
    /* error check */
    if (nmemb == 0 || size == 0)
        return NULL;

#ifdef DEBUG
    printf("[DEBUG]\t[pcalloc]\tcalling pmalloc with: %lu * %lu\n",
            (unsigned long)nmemb,
            (unsigned long)size);
    fflush(stdout);
#endif

    /* pmalloc already zeros the memory */
    return pmalloc(nmemb * size);
}
