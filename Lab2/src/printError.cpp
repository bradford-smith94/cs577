/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 printError.cpp
 * 09/22/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a std::string message
 * post: prints out message and exits with -1
 */
void printError(char* message)
{
    printf("[ERROR]\t%s\n", message);
    fflush(stdout);
    exit(-1);
}
