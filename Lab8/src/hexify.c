/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 hexify.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a char* string
 * post: parses string into an array of bytes
 * return: a struct that contains the hex value of string and it's length in
 *      bytes
 */
struct hexed hexify(char* string)
{
    char* tmp;
    int i;
    int j;
    unsigned char* bytes;
    struct hexed ret;

    /* remove the spaces from string and store in tmp */
    tmp = (char*)malloc(strlen(string));
    for (i = 0, j = 0; j < strlen(string); j++)
    {
        if (string[j] != '\t' && string[j] != ' ' && string[j] != '\n')
            tmp[i++] = string[j];
    }
    tmp[i] = '\0';

    /* lowercase the string */
    for (i = 0; tmp[i] != '\0'; i++)
        tmp[i] = tolower(tmp[i]);

    if (strlen(tmp) % 2) //odd length prepend a 0
        tmp = strcat("0", tmp);

#ifdef DEBUG
    printf("Mid convert: %s\n", tmp);
#endif

    bytes = (unsigned char*)malloc(strlen(tmp)*sizeof(unsigned char));

    /* turn into bytes */
    for (i = 0; i < (strlen(tmp) / 2); i++)
        sscanf(tmp + 2*i, "%02c", &bytes[i]);

    ret.bytes = bytes;
    ret.len = (strlen(tmp) / 2);

    free(tmp);
    return ret;
}
