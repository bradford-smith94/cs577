/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 main.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in int argc and char** argv command line args
 * post: runs the sniffer program
 * return: 0 on success something else on failure
 */
int main(int argc, char** argv)
{
    clock_t start; /* time started */
    clock_t end; /* time ended */
    double dtime; /* delta time */

    struct pcap_pkthdr header; /* packet header */

    pcap_t* pcapfd; /* points to global pcap file header */
    char errbuf[PCAP_ERRBUF_SIZE];

    int search_mode; /* flag to check if user specified search */
    int flows_mode; /* flag to check if user specified flows */
    char* search_pattern; /* search pattern user provided */

    int err_flag; /* flag signalling parameter error */

    search_mode = 0;
    flows_mode = 0;
    err_flag = 0;

    /* check parameters */
    if (argc < 2)
        err_flag = 1;
    else if (argc > 2)
    {
        /* need to check for commands */
        if (strcmp(argv[2], "search") == 0)
        {
            search_mode = 1;
            if (argc != 4)
                err_flag = 1;
            else
                search_pattern = argv[3];
        }
        else if (strcmp(argv[2], "flows") == 0)
        {
            flows_mode = 1;
            if (argc != 3)
                err_flag = 1;
        }
        else
            err_flag = 1;
    }
    if (err_flag)
    {
        printf("usage: %s <pcap file> [search <pattern> | flows]\n", argv[0]);
        fflush(stdout);
        exit(1);
    }

    /* open the pcap file */
    if ((pcapfd = pcap_open_offline(argv[1], errbuf)) == NULL)
    {
        printf("[ERROR]\tCannot open pcap file: %s\n", argv[1]);
        fflush(stdout);
        exit(1);
    }

    /* start timed code here */
    start = clock();

    /* check mode flags and execute */
    if (search_mode)
    {
#ifdef DEBUG
        printf("Search mode pattern: %s\n", search_pattern);
#endif
        search(pcapfd, header, search_pattern);
    }
    else if (flows_mode)
    {
#ifdef DEBUG
        printf("Flows finding mode\n");
#endif
        flows(pcapfd, header);
    }
    else
    {
#ifdef DEBUG
        printf("Packet counting mode\n");
#endif
        count(pcapfd, header);
    }

    /* end timed code here */
    end = clock();

    /* calculate time difference and print results*/
    dtime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution took %f seconds.\n", dtime);

    return 0;
}
