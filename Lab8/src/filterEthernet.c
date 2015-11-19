/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 filterEthernet.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

/* pre: takes in an int ethertype which is the ethertype of a packet from a pcap
 * post: returns the offset of the ethernet packet
 * return: the ether_offset of the packet or -1 if it is not an ethernet packet
 */
int filterEthernet(int ethertype)
{
    int ret;

    ret = 0;
    if (ethertype == ETH_P_IP)
        ret = 14;
    else if (ethertype == ETH_P_8021Q)
        ret = 18;
    /* else if (ethertype == ETH_P_ARP)
        ret = ??; */
    else
        ret = -1;

    return ret;
}
