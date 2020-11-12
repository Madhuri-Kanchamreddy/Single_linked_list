/*
Author : K.Madhuri
Roll Number : 201046022
Branch : Big Data and Data Analytics
*/
#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct _node_{
    int32_t data;
    Node *next;
};

typedef struct _slist_  Slist;

struct _slist_{
    Node *head;
    Node *tail;
    uint32_t length;
};

Slist slist_new(); // to create a new list
uint32_t slist_lookup(const Slist *list, int32_t key); // to search for an element
uint32_t slist_length(const Slist *list); // to find the length of the list
Slist* slist_addnode_head(Slist *list, int32_t value); // to add an element at the starting of the list
Slist* slist_addnode_tail(Slist *list, int32_t value); // to add an element at the end of the list
Slist* slist_delnode_head(Slist *list); // to delete an element at the start of the list
Slist* slist_delnode_tail(Slist *list); // to delete an element at the end of the list
uint32_t slist_max(const Slist *list); // to find the largest element in the list
uint32_t slist_min(const Slist *list); // to find the smallest element in the list
Slist* slist_addnode(Slist *list, int32_t value, int32_t key); // to add node at the specified place
Slist* slist_delnode(Slist *list, int32_t value); // to delete the specified node
Slist* slist_reverse(Slist *list); // to reverse the list
uint32_t slist_compare(Slist *list1, Slist *list2); // to compare two lists whether they are equal or not
Slist* slist_intersect(Slist *list1, Slist *list2); // to find the intersection of two lists
Slist* slist_union(Slist *list1, Slist *list2); // to find the union of two lists
Slist* unique_slist(Slist *list, int32_t value); // to insert unique elements in the list
#endif // SLIST_H_INCLUDED
