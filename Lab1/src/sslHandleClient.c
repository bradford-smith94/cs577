/* Bradford Smith
 * CS 577 Lab 1 sslHandleClient.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

/* pre: takes in an SSL* ssl
 * post: handles reading and writing to the client
 */
void sslHandleClient(SSL* ssl)
{
    char buffer[1024];
/*    char reply[1024];*/
    int sockfd;
    int bytesRead;

    if (SSL_accept(ssl) == -1)
    {
#ifdef DEBUG
        printDebug("Failed SSL accept");
#endif
        ERR_print_errors_fp(stderr);
    }
    else
    {
        sslShowCerts(ssl);
        bytesRead = SSL_read(ssl, buffer, sizeof(buffer));
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            printFromClient(buffer);
        }
        else
        {
#ifdef DEBUG
            printDebug("Read nothing");
#endif
            ERR_print_errors_fp(stderr);
        }
    }
}
