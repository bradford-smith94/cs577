/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 malloc.c
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "override.h"

/* overrides malloc(3) and provides guard-page protection
 */
void* malloc(size_t size)
{
    return pmalloc(size);
}
