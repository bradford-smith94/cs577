/* Bradford Smith (bsmith8)
 * CS 577 Lab1 proxy.h
 * 09/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */
#ifndef _PROXY_H_
#define _PROXY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <resolv.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

/* This is the header file for CS 577 Lab 1: MitM SSL Attack Proxy
 */
int         main(int, char**);
int         getPortFromArgs(int, char**);
void        printError(char*);
void        printDebug(char*);
void        printFromClient(char*);
void        printFromHost(char*);
char*       parseHTTPConnectForHost(char*);
int         parseHTTPConnectForPort(char*);
SSL*        connectHost(char*, int);
SSL_CTX*    sslServerInit();
void        sslLoadCerts(SSL_CTX*, char*, char*);
void        sslShowCerts(SSL*);

#endif /*_PROXY_H_*/
