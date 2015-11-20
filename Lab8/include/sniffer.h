/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 sniffer.h
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#ifndef _SNIFFER_H_
#define _SNIFFER_H_

#define _GNU_SOURCE /* for memmem */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>

#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <linux/if_ether.h> /* provides constants for common EtherTypes */
/* EtherType Constants include:
 * ETH_P_IP (0x0800) for ethernet IP
 * ETH_P_ARP (0x0806) for ARP
 * ETH_P_8021Q (0x8100) for VLAN tags
 */

/* a 'hexified' char* */
struct hexed
{
    unsigned char *bytes;
    size_t len;
};

/* linked list of tcp packets */
struct node
{
    struct iphdr *ip;
    struct tcphdr *tcp;
    struct node *n;
    struct node *p;
};

/* This is the header for the pcap sniffer program for Lab 8 */

int             main(int, char**);
int             filterEthernet(int);
struct hexed    hexify(char*);
void            count(pcap_t*, struct pcap_pkthdr);
void            search(pcap_t*, struct pcap_pkthdr, char*);
void            flows(pcap_t*, struct pcap_pkthdr, int);
struct node*    newNode(struct tcphdr*, struct iphdr*);
void            addNode(struct node**, struct node*);
void            deleteNode(struct node**, struct node*);

#endif /* _SNIFFER_H_ */
