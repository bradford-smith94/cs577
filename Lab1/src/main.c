/* Bradford Smith (bsmith8)
 * CS 577 Lab 1 main.c
 * 09/19/2015
 * "I plege my honor that I have abided by the Stevens Honor System."
 */
#include "proxy.h"

/* pre: takes in int argc and char** argv command line arguments
 * post: runs the SSL MitM Proxy Server
 * return: the program exit code (0 for success and something else for failure)
 */
int main(int argc, char** argv)
{
	socklen_t clientlen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;
    SSL_CTX *clientCTX;
    SSL *clientSSL;
    SSL *hostSSL;
    int sockfd;
    int clientfd;
    int hostfd;
	int port;
	int pid;
    int n;
    char* hostname;
    int hostport;
	char buffer[2048];
    const char* httpConnectReply = "HTTP/1.0 200 Connection established\n\nProxy-agent: Netscape-Proxy/1.1\n\n";


	port = getPortFromArgs(argc, argv);
	if(port < 0)
		printError("invalid port number");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printError("cannot create socket");

	serv_addr = *((struct sockaddr_in *)memset(&serv_addr, 0, sizeof(serv_addr)));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
		printError("cannot bind socket");

	printf("Server started on port %d\n", port);

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    clientCTX = sslServerInit();
    sslLoadCerts(clientCTX, "cert.pem", "key.pem");

	while(1)
	{
		listen(sockfd, 5);

		clientlen = sizeof(client_addr);
		clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
		if(clientfd < 0)
			printError("cannot accept connection");

		if((pid = fork()) < 0)
			printError("cannot fork process");
		else if(pid == 0)
		{
            n = read(clientfd, buffer, sizeof(buffer));
            if (n == -1)
                printError("cannot read on socket");

            hostname = parseHTTPConnectForHost(buffer);
            if (hostname == NULL)
                printError("parsing HTTP CONNECT string failed");
            hostport = parseHTTPConnectForPort(buffer);
            if (hostport == -1)
                printError("parsing HTTP CONNECT string failed");

#ifdef DEBUG
            printf("[DEBUG]\thostname: %s\n", hostname);
            printf("[DEBUG]\tport number: %d\n", hostport);
#endif

            n = write(clientfd, httpConnectReply, strlen(httpConnectReply));
            if (n == -1)
                printError("cannot write on socket");

            /* start SSL handshake with client */
            clientSSL = SSL_new(clientCTX);
            SSL_set_fd(clientSSL, clientfd);
            if (SSL_accept(clientSSL) == -1)
            {
#ifdef DEBUG
                printDebug("Failed SSL accept");
#endif
                ERR_print_errors_fp(stderr);
            }
            printf("Client:");
            sslShowCerts(clientSSL);

            hostSSL = connectHost(hostname, hostport);
            hostfd = SSL_get_fd(hostSSL);

#ifdef DEBUG
            printDebug("Starting communication loop");
#endif
            while (1)
            {
                printDebug("read from client");
                n = SSL_read(clientSSL, buffer, sizeof(buffer));
                if (n > 0)
                {
                    buffer[n] = '\0';
                    printFromClient(buffer);
                    SSL_write(hostSSL, buffer, strlen(buffer));
                }
                else if (n <= 0)
                    break;

                printDebug("read from server");
                n = SSL_read(hostSSL, buffer, sizeof(buffer));
                if (n > 0)
                {
                    buffer[n] = '\0';
                    printFromHost(buffer);
                    SSL_write(clientSSL, buffer, strlen(buffer));
                }
                else if (n <= 0)
                    break;
            }
            printf("Connection terminated\n");
            SSL_free(clientSSL);
            SSL_free(hostSSL);
            free(hostname);
            close(clientfd);
            SSL_CTX_free(clientCTX);
            close(hostfd);
            close(sockfd);
            exit(0);
		} /* if (child process) */
	} /* while */
} /* main */
