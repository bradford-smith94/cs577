/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 search.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a pcap_t* pcap, struct pcap_pkthdr hdr and a char* pattern
 * post: checks all packets in pcap to see if they match pattern and print out
 *      results of the packets that match
 */
void search(pcap_t *pcap, struct pcap_pkthdr hdr, char *pattern)
{
    const unsigned char *packet;
    unsigned char *ptr;
    int ethertype;
    int ether_offset;

    /* loop over all the packets */
    while ((packet = pcap_next(pcap, &hdr)))
    {
        ptr = (unsigned char*)packet;

        ethertype = ((int)(ptr[12]) << 8) | (int)ptr[13];
        ether_offset = 0;

        if ((ether_offset = filterEthernet(ethertype)) == -1)
            continue; /* this isn't an ethernet packet */
        ptr += ether_offset;

        struct ip *ip_hdr = (struct ip *)ptr; /* ip header struct */

        /* TODO: check if match */
    }
}
