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
    unsigned int tcp;
    unsigned int udp;
    unsigned int ip;
    unsigned int other;

    const unsigned char *packet;
    unsigned char *ptr;
    int ethertype;
    int ether_offset;

    struct hexed s_hex;

    s_hex = hexify(pattern);

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

        /* check memory for a match */
        if (memmem(packet, ip_hdr->tot_len, s_hex.bytes, s_hex.len) != NULL)
        {
            if (ip_hdr->protocol == IPPROTO_TCP) /* if packet is TCP */
            {
                struct tcphdr *tcp_hdr = (struct tcphdr*)ip_hdr;
                printf("TCP %s:%d %s:%d %d\n",
                        inet_ntoa((*(struct in_addr*)&ip_hdr->saddr)),
                        tcp_hdr->source,
                        inet_ntoa((*(struct in_addr*)&ip_hdr->daddr)),
                        tcp_hdr->dest,
                        ip_hdr->id);
                tcp++;
            }
            else if (ip_hdr->protocol == IPPROTO_UDP) /* if packet is UDP */
            {
                struct udphdr *udp_hdr = (struct udphdr*)ip_hdr;
                printf("UDP %s:%d %s:%d %d\n",
                        inet_ntoa((*(struct in_addr*)&ip_hdr->saddr)),
                        udp_hdr->source,
                        inet_ntoa((*(struct in_addr*)&ip_hdr->daddr)),
                        udp_hdr->dest,
                        ip_hdr->id);
                udp++;
            }
            else if (ip_hdr->protocol == IPPROTO_IP) /* if packet is other IP */
            {
                printf("IP %s %s %d\n",
                        inet_ntoa((*(struct in_addr*)&ip_hdr->saddr)),
                        inet_ntoa((*(struct in_addr*)&ip_hdr->daddr)),
                        ip_hdr->id);
                ip++;
            }
            else
                other++;
        }
    }

    /* print out counts */
    printf("Search Matched:\
            \n\t%u IP packets\
            \n\t%u TCP packets\
            \n\t%u UDP packets\
            \n\tand %u other ethernet packets\n",
            ip,
            tcp,
            udp,
            other);
}
