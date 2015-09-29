/* Bradford Smith (bsmith8)
 * CS 577 Lab1 printFormatting.c
 * 09/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */
#include "proxy.h"

/* pre: takes in a char* message and an int ecode
 * post: prints message and exits with error code ecode
 */
void printError(char* message)
{
    fprintf(stderr, "ERROR: %s\n", message);
    exit(-1);
}

/* pre: takes in a char* message
 * post: prints a debug stylized message
 */
void printDebug(char* message)
{
    printf("[DEBUG]\t%s\n", message);
}

/* pre: takes in a char* message
 * post: prints out the message with some formatting so that we know it is
 *      coming from the client
 */
void printFromClient(char* message)
{
    printf(">>>Client>>>\n%s\n<<<\n", message);
}

/* pre: takes in a char* message
 * post: prints out the message with some formatting so that we know it is
 *      coming from the host
 */
void printFromHost(char* message)
{
    printf("<<<Host<<<\n%s\n>>>\n", message);
}

