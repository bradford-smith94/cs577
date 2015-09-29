/* Bradford Smith (bsmith8)
 * CS 577 Lab1 createSocket.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */
#include "proxy.h"

/* pre: takes in an int portnum
 * post: creates binds and starts listening on a socket
 * return: the socket file descriptor as an int
 */
int createSocket(int portnum)
{
    struct sockaddr_in server;
    int sockfd;

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(portnum);
    server.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        printError("could not open socket");

    bindAndListen(sockfd, &server);

    return sockfd;
}
