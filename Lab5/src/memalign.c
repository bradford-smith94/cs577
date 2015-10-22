/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 memalign.c
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "override.h"

/* overrides memalign(3) and adds guard-page protection
 */
void* memalign(size_t boundary, size_t size)
{
    return pmemalign(boundary, size);
}
