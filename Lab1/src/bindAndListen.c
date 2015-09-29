/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 bindAndListen.c
 * 09/17/2015
 * "I plege my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

void bindAndListen(int sockfd, struct sockaddr_in *addr)
{
    if (bind(sockfd, (struct sockaddr *) addr, sizeof(*addr)) < 0)
        printError("could not bind socket");

    if (listen(sockfd, 5) != 0)
        printError("could not listen on socket");
}
