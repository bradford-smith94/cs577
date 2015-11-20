/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 flows.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in a pcap_t* pcap, a struct pcap_pkthdr hdr and an int
 *      reconstruct
 * post: loop through the packets in pcap and search for SSL/TLS flows in the
 *      TCP packets, if reconstruct is not zero a linked list will be used in
 *      attempt to reconstruct and differentiate TCP flows
 */
void flows(pcap_t *pcap, struct pcap_pkthdr hdr, int reconstruct)
{
    unsigned int flows;

    const unsigned char *packet;
    unsigned char *ptr;
    int ethertype;
    int ether_offset;

    char* tls_seqs[] = {
        "16 03 00", "16 03 01",
        "16 03 02", "16 03 03",
        "14 03 00", "14 03 01",
        "14 03 02", "14 03 03",
        "17 03 00", "17 03 01",
        "17 03 02", "17 03 03"};
    int i;
    int max;
    struct hexed s_hex;
    struct node *head;
    struct node *node;

    if (reconstruct)
        head = newNode(NULL, NULL);

    flows = 0;

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
        if (ip_hdr->protocol != IPPROTO_TCP) /* if packet is not TCP */
            continue;

        struct tcphdr *tcp_hdr = (struct tcphdr*)ip_hdr;

        /* for all possible SSL/TLS patterns */
        for (i = 0; i < 12; i++)
        {
            s_hex = hexify(tls_seqs[i]);

            /* if this is SSL/TLS packet */
            if (memmem(packet, ip_hdr->tot_len, s_hex.bytes, s_hex.len) != NULL)
            {
                if (!reconstruct)
                {
                    printf("%s:%d %s:%d %u\n",
                            inet_ntoa((*(struct in_addr*)&ip_hdr->saddr)),
                            tcp_hdr->source,
                            inet_ntoa((*(struct in_addr*)&ip_hdr->daddr)),
                            tcp_hdr->dest,
                            ip_hdr->id);
                    flows++;
                }
                else
                    addNode(&head, newNode(tcp_hdr, ip_hdr));
                break; /* don't need to check other patterns if we get a match */
            }
        }
    }

    if (reconstruct)
    {
        /* sort by tcp seq */
        /* list is too bare-bones to sort :( */
    }

    printf("SSL/TLS Flows Discovered: %u\n",
            flows);
}
