/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 calloc.c
 * 10/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "override.h"

/* overrides calloc(3) and provides guard-page protection
 */
void* calloc(size_t nmemb, size_t size)
{
    return pcalloc(nmemb, size);
}
