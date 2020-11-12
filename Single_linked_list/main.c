/*
Author : K.Madhuri
Roll Number : 201046022
Branch : Big Data and Data Analytics
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"
#include "slist.c"
#include "dlist.h"
#include "dlist.c"

void test_empty_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list) == 0);
}

void test_add_at_head(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    assert(slist_length(list) == 1);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    assert(slist_length(list) == 3);
    assert(slist_lookup(list, 20) == 1);
}

void test_add_at_tail(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_tail(list, 10);
    assert(slist_length(list) == 1);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 30);
    assert(slist_length(list) == 3);
    assert(slist_lookup(list, 20) == 1);
}

void test_delete_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_tail(list, 10);
    list = slist_addnode_tail(list, 20);
    list = slist_addnode_tail(list, 30);
    list = slist_delnode_tail(list);
    assert(slist_length(list) == 2);
    assert(slist_lookup(list, 30) == 0);
    assert(slist_lookup(list, 20) == 1);
    list = slist_addnode_tail(list, 40);
    list = slist_addnode_tail(list, 50);
    assert(slist_length(list) == 4);
}

void test_delete_tail(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_delnode_head(list);
    assert(slist_length(list) == 2);
    assert(slist_lookup(list, 30) == 0);
    assert(slist_lookup(list, 20) == 1);
    list = slist_addnode_head(list, 40);
    list = slist_addnode_head(list, 50);
    assert(slist_length(list) == 4);
}

void test_search_in_list(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    assert(slist_lookup(list, 20) == 1);
}

void test_find_max(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_addnode_head(list, 5);
    list = slist_addnode_head(list, 25);
    list = slist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
    uint32_t max = slist_max(list);
}

void test_find_min(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_addnode_head(list, 5);
    list = slist_addnode_head(list, 25);
    list = slist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
    uint32_t min = slist_min(list);
}

void test_addnode_random(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_addnode_head(list, 5);
    list = slist_addnode_head(list, 25);
    list = slist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
    list = slist_addnode(list, 60, 5);
    assert(slist_length(list) == 7);
}

void test_delnode_random(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_addnode_head(list, 5);
    list = slist_addnode_head(list, 25);
    list = slist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
    list = slist_delnode(list, 25);
    assert(slist_length(list) == 5);
}

void test_reverse(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list, 10);
    list = slist_addnode_head(list, 20);
    list = slist_addnode_head(list, 30);
    list = slist_addnode_head(list, 5);
    list = slist_addnode_head(list, 25);
    list = slist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
    list = slist_reverse(list);
}

void test_compare_lists(){
    Slist s1, s2;
    s1 = slist_new();
    s2 = slist_new();
    Slist *list1 = &s1;
    Slist *list2 = &s2;
    list1 = slist_addnode_head(list1, 10);
    list1 = slist_addnode_head(list1, 20);
    list1 = slist_addnode_head(list1, 30);
    list1 = slist_addnode_head(list1, 5);
    list1 = slist_addnode_head(list1, 25);
    list1 = slist_addnode_head(list1, 55);
    assert(slist_length(list1) == 6);
    list2 = slist_addnode_head(list2, 10);
    list2 = slist_addnode_head(list2, 5);
    list2 = slist_addnode_head(list2, 55);
    list2 = slist_addnode_head(list2, 25);
    list2 = slist_addnode_head(list2, 30);
    list2 = slist_addnode_head(list2, 20);
    assert(slist_length(list2) == 6);
    assert(slist_compare(list1, list2) == 1);
}

void test_intersection(){
    Slist s1, s2, inter;
    s1 = slist_new();
    s2 = slist_new();
    inter = slist_new();
    Slist *list1 = &s1;
    Slist *list2 = &s2;
    Slist *intersect = &inter;
    list1 = slist_addnode_head(list1, 10);
    list1 = slist_addnode_head(list1, 20);
    list1 = slist_addnode_head(list1, 30);
    list1 = slist_addnode_head(list1, 5);
    list1 = slist_addnode_head(list1, 25);
    list1 = slist_addnode_head(list1, 55);
    assert(slist_length(list1) == 6);
    list2 = slist_addnode_head(list2, 10);
    list2 = slist_addnode_head(list2, 5);
    list2 = slist_addnode_head(list2, 50);
    list2 = slist_addnode_head(list2, 25);
    list2 = slist_addnode_head(list2, 35);
    list2 = slist_addnode_head(list2, 20);
    assert(slist_length(list2) == 6);
    intersect = slist_intersect(list1, list2);
}

void test_union(){
    Slist s1, s2, union1;
    s1 = slist_new();
    s2 = slist_new();
    union1 = slist_new();
    Slist *list1 = &s1;
    Slist *list2 = &s2;
    Slist *union_list = &union1;
    list1 = slist_addnode_head(list1, 10);
    list1 = slist_addnode_head(list1, 20);
    list1 = slist_addnode_head(list1, 30);
    list1 = slist_addnode_head(list1, 5);
    list1 = slist_addnode_head(list1, 25);
    list1 = slist_addnode_head(list1, 55);
    assert(slist_length(list1) == 6);
    list2 = slist_addnode_head(list2, 10);
    list2 = slist_addnode_head(list2, 5);
    list2 = slist_addnode_head(list2, 50);
    list2 = slist_addnode_head(list2, 25);
    list2 = slist_addnode_head(list2, 35);
    list2 = slist_addnode_head(list2, 20);
    assert(slist_length(list2) == 6);
    union_list = slist_union(list1, list2);
}

void test_unique_list(){
    Slist s1;
    s1 = slist_new();
    Slist *list = &s1;
    list = unique_slist(list, 10);
    assert(slist_length(list) == 1);
    list = unique_slist(list, 20);
    assert(slist_length(list) == 2);
    list = unique_slist(list, 30);
    assert(slist_length(list) == 3);
    list = unique_slist(list, 25);
    assert(slist_length(list) == 4);
    list = unique_slist(list, 35);
    assert(slist_length(list) == 5);
}

void test_empty_double_list(){
    Dlist d1 = new_list();
    Dlist *list = &d1;
    assert(slist_length(list) == 0);
}

void test_double_list_add_at_head(){
    Dlist d1 = new_list();
    Dlist *list = &d1;
    assert(slist_length(list) == 0);
    list = dlist_addnode_head(list, 10);
    assert(slist_length(list) == 1);
    list = dlist_addnode_head(list, 20);
    assert(slist_length(list) == 2);
    list = dlist_addnode_head(list, 30);
    assert(slist_length(list) == 3);
    list = dlist_addnode_head(list, 5);
    assert(slist_length(list) == 4);
    list = dlist_addnode_head(list, 25);
    assert(slist_length(list) == 5);
    list = dlist_addnode_head(list, 55);
    assert(slist_length(list) == 6);
}

void test_double_list_add_at_tail(){
    Dlist d1 = new_list();
    Dlist *list = &d1;
    assert(slist_length(list) == 0);
    list = dlist_addnode_tail(list, 10);
    assert(slist_length(list) == 1);
    list = dlist_addnode_tail(list, 20);
    assert(slist_length(list) == 2);
    list = dlist_addnode_tail(list, 30);
    assert(slist_length(list) == 3);
    list = dlist_addnode_tail(list, 5);
    assert(slist_length(list) == 4);
    list = dlist_addnode_tail(list, 25);
    assert(slist_length(list) == 5);
    list = dlist_addnode_tail(list, 55);
    assert(slist_length(list) == 6);
}

void test_delnode_double_list(){
    Dlist d1 = new_list();
    Dlist *list = &d1;
    assert(slist_length(list) == 0);
    list = dlist_addnode_tail(list, 10);
    list = dlist_addnode_tail(list, 20);
    list = dlist_addnode_tail(list, 30);
    list = dlist_addnode_tail(list, 5);
    list = dlist_addnode_tail(list, 25);
    list = dlist_addnode_tail(list, 55);
    list = dlist_delnode(list, 10);
    assert(dlist_length(list) == 5);
}

void test_search_double_list(){
    Dlist d1 = new_list();
    Dlist *list = &d1;
    assert(slist_length(list) == 0);
    list = dlist_addnode_tail(list, 10);
    list = dlist_addnode_tail(list, 20);
    list = dlist_addnode_tail(list, 30);
    list = dlist_addnode_tail(list, 5);
    list = dlist_addnode_tail(list, 25);
    list = dlist_addnode_tail(list, 55);
    assert(dlist_lookup(list, 20) == 1);
}

int main()
{
    test_empty_list();
    test_add_at_head();
    test_add_at_tail();
    test_delete_head();
    test_delete_tail();
    test_find_max();
    test_find_min();
    test_addnode_random();
    test_delnode_random();
    test_reverse();
    test_compare_lists();
    test_intersection();
    test_union();
    test_search_in_list();
    test_unique_list();
    test_double_list_add_at_head();
    test_double_list_add_at_tail();
    test_delnode_double_list();
    test_search_double_list();
    return 0;
}
