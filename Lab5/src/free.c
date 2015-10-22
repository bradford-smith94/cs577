/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 free.c
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "override.h"

/* overrides free(3) and provide guard page protection
 */
void free(void* ptr)
{
    pfree(ptr);
}
