/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 printDebug.cpp
 * 09/22/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a std::string message
 * post: prints out message with debug styling and flushes stdout
 */
void printDebug(char* message)
{
    printf("[DEBUG]\t%s\n", message);
    fflush(stdout);
}
