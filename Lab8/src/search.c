/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 search.c
 * 11/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a pcap_t* pcap, struct pcap_pkthdr hdr and an unsigned int*
 *      matches
 * post: checks all packets in pcap to see if they are a match and increments
 *      the number of matches pointed to by matches
 */
void search(pcap_t *pcap, struct pcap_pkthdr hdr, char *pattern, unsigned int *ip,
        unsigned int *tcp, unsigned int *udp, unsigned int *other)
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

        if (ethertype == ETH_P_IP)
            ether_offset = 14;
        else if (ethertype == ETH_P_8021Q)
            ether_offset = 18;
        else
            continue; /* this isn't an ethernet packet */
        ptr += ether_offset;

        struct ip *ip_hdr = (struct ip *)ptr; /* ip header struct */

        /* TODO: check if match */
    }
}
