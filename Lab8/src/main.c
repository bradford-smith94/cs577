/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 main.c
 * 11/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in int argc and char** argv command line args
 * post: runs the sniffer program
 * return: 0 on success something else on failure
 */
int main(int argc, char** argv)
{
    unsigned int ip_count; /* count of IP packets */
    unsigned int tcp_count; /* count of TCP packets */
    unsigned int udp_count; /* count of UDP packets */
    unsigned int match_count; /* count of search matches */

    clock_t start; /* time started */
    clock_t end; /* time ended */
    double dtime; /* delta time */

    struct pcap_pkthdr header; /* packet header */
    const unsigned char *packet; /* full packet */

    pcap_t* pcapfd;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc < 2)
    {
        printf("usage: %s <pcap file>\n", argv[0]);
        fflush(stdout);
        exit(1);
    }
    else if (argc > 2)
    {
        /* need to check for commands */
        printf("usage: %s <pcap file>\n", argv[0]);
        printf("more advanced functionality not implemented yet\n");
        fflush(stdout);
        exit(1);
    }

    if ((pcapfd = pcap_open_offline(argv[1], errbuf)) == NULL)
    {
        printf("Cannot open pcap file!\n");
        fflush(stdout);
        exit(1);
    }

    /* initialize counts */
    ip_count = 0;
    tcp_count = 0;
    udp_count = 0;
    match_count = 0;

    /* start timed code here */
    start = clock();

    /* count will update the counts of the integers */
    count(pcapfd, header, &ip_count, &tcp_count, &udp_count);

    /* end timed code here */
    end = clock();

    /* calculate time difference */
    dtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Processed: %u IP packets, %u TCP packets, and %u UDP packets in %f seconds.\n",
            ip_count,
            tcp_count,
            udp_count,
            dtime);

    return 0;
}
