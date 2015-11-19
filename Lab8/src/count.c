/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 count.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a pcap_t* pcap and a struct pcap_pkthdr hdr
 * post: loop through the packets in pcap and count the number of ip, tcp and
 *      udp packets, then print out the counts
 */
void count(pcap_t *pcap, struct pcap_pkthdr hdr)
{
    unsigned int tcp;
    unsigned int udp;
    unsigned int ip;
    unsigned int other;

    const unsigned char *packet;
    unsigned char *ptr;
    int ethertype;
    int ether_offset;

    /* initialize counts */
    tcp = 0;
    udp = 0;
    ip = 0;
    other = 0;

    /* loop over all the packets */
    while ((packet = pcap_next(pcap, &hdr)))
    {
        ptr = (unsigned char*)packet;

        ethertype = ((int)(ptr[12]) << 8) | (int)ptr[13];
        ether_offset = 0;

        if ((ether_offset = filterEthernet(ethertype)) == -1)
            continue; /* this isn't an ethernet packet */
        ptr += ether_offset;

        struct iphdr *ip_hdr = (struct iphdr *)ptr; /* ip header struct */

        /* check if ip_hdr is IP/TCP/UDP */
        if (ip_hdr->protocol == IPPROTO_TCP) /* if packet is TCP */
            tcp++;
        else if (ip_hdr->protocol == IPPROTO_UDP) /* if packet is UDP */
            udp++;
        else if (ip_hdr->protocol == IPPROTO_IP) /* if packet is other IP */
            ip++;
        else
            other++;
    }

    /* print out counts */
    printf("Counted:\
            \n\t%u IP packets\
            \n\t%u TCP packets\
            \n\t%u UDP packets\
            \n\tand %u other ethernet packets\n",
            ip,
            tcp,
            udp,
            other);
}
