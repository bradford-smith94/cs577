/* Bradford Smith
 * CS 577 Lab 1 getPortFromArgs.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

/* pre: takes in int argc and char** argv command line arguments from main
 * post: checks to see if a port number was provided and returns it
 * return: 8000 or the port number provided as arguments if there was one
 */
int getPortFromArgs(int argc, char** argv)
{
    int ret;
    const int portDefault = 8000;

    if (argc < 2)
    {
#ifdef DEBUG
        printDebug("No port number provided, using :8000");
#endif
        ret = portDefault;
    }
    else if (argc == 2)
        ret = atoi(argv[1]);
    else
        ret = -1;

    if (ret <= 0)
        ret = portDefault;
    return ret;
}
