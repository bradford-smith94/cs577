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
    unsigned int other_count; /* count of other packets */

    clock_t start; /* time started */
    clock_t end; /* time ended */
    double dtime; /* delta time */

    struct pcap_pkthdr header; /* packet header */

    pcap_t* pcapfd; /* points to global pcap file header */
    char errbuf[PCAP_ERRBUF_SIZE];

    int search_mode; /* flag to check if user specified search */
    char* search_pattern; /* search pattern user provided */

    search_mode = 0;
    if (argc < 2)
    {
        printf("usage: %s <pcap file>\n", argv[0]);
        fflush(stdout);
        exit(1);
    }
    else if (argc > 2)
    {
        /* need to check for commands */
        search_mode = 1;
    }

    /* open the pcap file */
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
    other_count = 0;

    /* start timed code here */
    start = clock();

    if (search_mode)
    {
        search(pcapfd, header, search_pattern, &ip_count, &tcp_count, &udp_count, &other_count);
    }
    else
    {
        /* count will update the counts of the integers */
        count(pcapfd, header, &ip_count, &tcp_count, &udp_count, &other_count);
    }

    /* end timed code here */
    end = clock();

    /* calculate time difference */
    dtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Counted:\
            \n\t%u IP packets\
            \n\t%u TCP packets\
            \n\t%u UDP packets\
            \n\tand %u other ethernet packets\
            \nin %f seconds.\n",
            ip_count,
            tcp_count,
            udp_count,
            other_count,
            dtime);

    printf("Execution took %f seconds.\n", dtime);

    return 0;
}
