/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 httpConnect.c
 * 09/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "proxy.h"
/* CONNECT target_IP:target_port [http version]\n[http headers\n]\n */

/* pre: takes in a char* connectString
 * post: parses connectString to find the target_IP
 * return: malloc'd char* of the target_IP or NULL if connectString is not
 *      correct
 */
char* parseHTTPConnectForHost(char* connectString)
{
    char* host;
    short count;

    host = (char*)malloc(sizeof(char)*10);

    if (!strncmp(connectString, "CONNECT", 7))
    {
        /* starts with CONNECT */
        connectString += 8;
        for (count = 0; *connectString != ':'; count++, connectString++)
        {
            host[count] = *connectString;
        }
        host[count] = '\0';
    }
    else
        host = NULL;
#ifdef DEBUG
    printf("[DEBUG]\tParsed hostname: %s\n", host);
#endif
    return host;
}

/* pre: takes in a char* connectString
 * post: parses connectString to find the target_port
 * return: int of the target_port or -1 if connectString is not correct
 */
int parseHTTPConnectForPort(char* connectString)
{
    int port;
    char* tempPort;
    short count;

    tempPort = (char*)malloc(sizeof(char)*10);

    if (!strncmp(connectString, "CONNECT", 7))
    {
        for (; *connectString != ':'; connectString++);
        connectString++;
        for (count = 0; *connectString != ' ' && *connectString != '\n'; count++, connectString++)
        {
            tempPort[count] = *connectString;
        }
        tempPort[count] = '\0';
        port = atoi(&tempPort[0]);
    }
    else
        port = -1;
#ifdef DEBUG
    printf("[DEBUG]\tParsed port: %d\n", port);
#endif
    free(tempPort);
    return port;
}
