/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 sslServerInit.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

/* pre: none
 * post: SSL server context is initialized
 * return: the SSL_CTX of the server context
 */
SSL_CTX* sslServerInit()
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = SSLv3_server_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL)
    {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    return ctx;
}
