/*
Author : K.Madhuri
Roll Number : 201046022
Branch : Big Data and Data Analytics
*/
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

Slist slist_new(){
    Slist s1 = {NULL, NULL, 0};
    return s1;
}

uint32_t slist_length(const Slist *list){
    assert(list!=NULL);
    return list->length;
}

static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

Slist* slist_addnode_head(Slist *list, int32_t val){
    assert(list!=NULL);
    Node *new_node = _get_new_node_(val);
    new_node->next = list->head;
    list->head = new_node;
    if(list->tail == NULL){
        list->tail = new_node;
    }
    else{
        list->head = list->tail = new_node;
    }
    list->length += 1;
    printf("%d\n",list->length);
    assert((list->length == 1) || (list->length > 1));
    return list;
}

Slist* slist_addnode_tail(Slist * list, int32_t val){
    assert(list!= NULL);
    Node *new_node = _get_new_node_(val);
    if (list->tail != NULL){
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else{
        list->head = list->tail = new_node;
    }
    ++list->length;
    assert((list->length == 1) || (list->length > 1));
    return list;
}

uint32_t slist_lookup(const Slist *list, int32_t key){
    assert(list!=NULL);
    Node *curr = list->head;
    for(curr = list->head; curr!=NULL; curr=curr->next){
        if(curr->data == key){
            return 1;
        }
    }
    return 0;
}

Slist* slist_delnode_head(Slist *list){
    assert(list!=NULL);
    Node *temp;
    if(list->head != NULL){
        temp = list->head;
        list->head = list->head->next;
        if(list->head==NULL){
            list->tail = NULL;
        }
        --list->length;
        free(temp);
    }
    return list;
}

Slist* slist_delnode_tail(Slist *list){
    assert(list!=NULL);
    Node *last, *curr;
    if(list->tail != NULL){
        last = list->tail;
        if(list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else{
            for(curr = list->head; curr->next!=last; curr=curr->next);
            list->tail = curr;
            curr->next = NULL;
        }
        --list->length;
        free(last);
    }
    return list;
}

uint32_t slist_max(const Slist *list){
    uint32_t max = list->head->data;
    Node *temp = list->head;
    for(temp = list->head->next; temp != NULL; temp = temp->next){
        if(temp->data > max){
            max = temp->data;
        }
    }
    return max;
}

uint32_t slist_min(const Slist *list){
    uint32_t min = list->head->data;
    Node *temp = list->head;
    for(temp = list->head->next; temp != NULL; temp = temp->next){
        if(temp->data < min){
            min = temp->data;
        }
    }
    return min;
}
Slist* slist_addnode(Slist *list, int32_t value, int32_t key){
    assert(list!=NULL);
    Node *curr = list->head;
    Node *new_node = _get_new_node_(value);
    for(curr = list->head; curr!=NULL; curr=curr->next){
        if(curr->data == key){
            new_node->next = curr->next;
            curr->next = new_node;
            break;
        }
    }
    ++list->length;
    return curr;
}
Slist* slist_delnode(Slist *list, int32_t value){
    assert(list!=NULL);
    Node *temp, *prev;
    if(list->head == list->tail){
        temp = list->head;
        list->head = list->tail = NULL;
    }
    Node *curr = list->head;
    for(curr = list->head; curr!=NULL; curr = curr->next){
        prev = curr;
        if(curr->data == value){
            prev->next = curr->next;
            temp = curr;
            temp->next = NULL;
            break;
        }
    }
    free(temp);
    --list->length;
    return curr;
}

Slist* slist_reverse(Slist *list){
    Node* prev   = NULL;
    Node* current = list->head;
    Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
    return next;
}

uint32_t slist_compare(Slist *list1, Slist *list2){
    Node *temp1;
    uint32_t count = 0;
    for(temp1 = list1->head; temp1 != NULL; temp1 = temp1->next){
        if(slist_lookup(list2, temp1->data))
            count++;
    }
    if(count == list1->length && count == list2->length)
        return 1;
    else
        return 0;
}

Slist* slist_intersect(Slist *list1, Slist *list2){
    Node *temp1,*intersect;
    for(temp1 = list1->head; temp1 != NULL; temp1 = temp1->next){
        if(slist_lookup(list2, temp1->data)){
            if(intersect == NULL){
                Node *new_node = _get_new_node_(temp1->data);
                intersect = new_node;
            }
            else{
                intersect->next = temp1;
                intersect->next = NULL;
            }
        }
    }
    return intersect;
}

Slist* slist_union(Slist *list1, Slist *list2){
    Node *temp1, *union_list, *temp2;
    for(temp1 = list1->head; temp1 != NULL; temp1 = temp1->next){
        if(union_list == NULL){
            union_list = temp1;
            union_list->next = NULL;
        }
        else{
            union_list->next = temp1;
            union_list->next = NULL;
        }
    }
    for(temp2 = list2->head; temp2 != NULL; temp2 = temp2->next){
        if(union_list == NULL){
            union_list = temp2;
            union_list->next = NULL;
        }
        else{
            union_list->next = temp2;
            union_list->next = NULL;
        }
    }
    return union_list;
}

Slist* unique_slist(Slist *list, int32_t value){
    assert(list!= NULL);
    if(!slist_lookup(list, value)){
        Node *new_node = _get_new_node_(value);
        if (list->tail != NULL){
            list->tail->next = new_node;
            list->tail = new_node;
        }
        else{
            list->head = list->tail = new_node;
        }
        ++list->length;
    }
    assert((list->length == 1) || (list->length > 1));
    return list;
}
