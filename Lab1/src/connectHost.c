/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 connectHost.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

SSL* connectHost(char *hostname, int port)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct hostent *host;
    struct sockaddr_in addr;

    method = SSLv3_client_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL)
    {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }

    if ((host = gethostbyname(hostname)) == NULL)
        printError("couldn't get hostname");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
    {
        close(sockfd);
        printError("couldn't connect to hostname");
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) == -1)
        ERR_print_errors_fp(stderr);
    else
    {
        printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
        printf("Server:");
        sslShowCerts(ssl);
    }

    return ssl;
}
