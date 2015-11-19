/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 sniffer.h
 * 11/18/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#ifndef _SNIFFER_H_
#define _SNIFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <time.h>

#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <linux/if_ether.h> /* provides constants for common EtherTypes */
/* EtherType Constants include:
 * ETH_P_IP (0x0800) for ethernet IP
 * ETH_P_ARP (0x0806) for ARP
 * ETH_P_8021Q (0x8100) for VLAN tags
 */

/* This is the header for the pcap sniffer program for Lab 8 */

int     main(int, char**);
void    count(pcap_t*, struct pcap_pkthdr, unsigned int*, unsigned int*,
        unsigned int*, unsigned int*);
void    search(pcap_t*, struct pcap_pkthdr, char*, unsigned int*,
        unsigned int*, unsigned int*, unsigned int*);

/* useful libpcap functions:
 * pcap_open_offline()
 * pcap_loop()
 * pcap_next()
 * pcap_create()
 */

#endif /* _SNIFFER_H_ */
