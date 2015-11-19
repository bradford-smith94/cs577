/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 count.c
 * 11/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a pcap_t* pcap, struct pcap_pkthdr hdr, and three unsigned
 *      int*'s ip, tcp and udp
 * post: loop through the packets in pcap and update the counts of ip, tcp and
 *      udp with the number of those packet types found
 */
void count(pcap_t *pcap, struct pcap_pkthdr hdr, unsigned int *ip,
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

        struct iphdr *ip_hdr = (struct iphdr *)ptr; /* ip header struct */

        /* check if ip_hdr is IP/TCP/UDP */
        if (ip_hdr->protocol == IPPROTO_TCP) /* if packet is TCP */
            (*tcp)++;
        else if (ip_hdr->protocol == IPPROTO_UDP) /* if packet is UDP */
            (*udp)++;
        else if (ip_hdr->protocol == IPPROTO_IP) /* if packet is other IP */
            (*ip)++;
        else
            (*other)++;
    }
}
