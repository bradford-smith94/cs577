/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 sslCerts.c
 * 09/17/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"

/* pre: takes in a SSL_CTX* ctx, char* certFile and char* keyFile
 * post: initializes the server certificate and private key from certFile and
 *      keyfile
 */
void sslLoadCerts(SSL_CTX* ctx, char* certFile, char* keyFile)
{
    /* set certificate from certFile */
    if (SSL_CTX_use_certificate_file(ctx, certFile, SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    /* set private key from keyFile */
    if (SSL_CTX_use_PrivateKey_file(ctx, keyFile, SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stderr);
        exit(-1);
    }
    /* verify */
    if (!SSL_CTX_check_private_key(ctx))
        printError("private key doesn't match the certificate");
}

/* pre: takes in SSL* ssl
 * post: prints out the certificate information if certificates are found
 */
void sslShowCerts(SSL* ssl)
{
    X509 *cert;
    char *data;

    cert = SSL_get_peer_certificate(ssl);
    if (cert != NULL)
    {
        printf(" Certificates:\n");
        data = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", data);
        free(data);
        data = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", data);
        free(data);
        X509_free(cert);
    }
    else
        printf(" No Certificates\n");
}
