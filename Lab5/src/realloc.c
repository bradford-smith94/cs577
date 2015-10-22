/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 realloc.c
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "override.h"

/* overrides realloc(3) and adds guard-page protection
 */
void* realloc(void* ptr, size_t size)
{
    return prealloc(ptr, size);
}
