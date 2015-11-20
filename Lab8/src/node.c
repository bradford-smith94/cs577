/* Bradford Smith (bsmith8)
 * CS 577 Lab 8 node.c
 * 11/19/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "sniffer.h"

struct node* newNode(struct tcphdr *tcp, struct iphdr *ip)
{
    struct node *ret;

    ret = (struct node*)malloc(sizeof(struct node));
    ret->ip = ip;
    ret->tcp = tcp;
    ret->n = NULL;
    ret->p = NULL;

    return ret;
}

void addNode(struct node **head, struct node *add)
{
    if ((*head)->ip == NULL)
        (*head) = add;
    else
    {
        while ((*head)->n != NULL)
            (*head)++;
        (*head)->n = add;
        add->p = (*head);
    }
}

void deleteNode(struct node **head, struct node *del)
{
    while ((*head)->n != del)
        (*head)++;
    (*head)->n = del->n;
    free(del);
    if ((*head)->n != NULL);
        ((*head)->n)->p = (*head);
}
