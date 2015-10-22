/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 main.c
 * 10/21/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* a simple test main for pmalloc */
int main()
{
    char* test;

#ifdef DEBUG
    printf("[DEBUG]\tStarting debug testmain\n\n\n");
    printf("[DEBUG]\tsizeof void*: %lu\n\tsizeof size_t: %lu\n",
            (unsigned long)sizeof(void*),
            (unsigned long)sizeof(size_t));
#endif
    printf("Testing malloc with: %lu\n", (10*sizeof(char)));
    fflush(stdout);

    test = (char*)malloc(10*sizeof(char));

    printf("It worked!\n");

    printf("Testing free\n");
    fflush(stdout);

    free(test);

    printf("It worked!\n");
    return 0;
}
