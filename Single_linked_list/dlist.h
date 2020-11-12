/*
Author : K.Madhuri
Roll Number : 201046022
Branch : Big Data and Data Analytics
*/
#include <stdint.h>
#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED

typedef struct _dnode_ DNode;

struct _dnode_{
    int32_t data;
    DNode *prev;
    DNode *next;
};

typedef struct _dlist_ Dlist;

struct _dlist_{
    DNode *head;
    DNode *tail;
    uint32_t length;
};

Dlist new_list();
uint32_t dlist_lookup(const Dlist *list, int32_t key);
uint32_t dlist_length(const Dlist *list);
Dlist* dlist_addnode_head(Dlist *list, int32_t value);
Dlist* dlist_addnode_tail(Dlist *list, int32_t value);
Dlist* dlist_delnode(Dlist *list, int32_t value)

#endif // DLIST_H_INCLUDED
