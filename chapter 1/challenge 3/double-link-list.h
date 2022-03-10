#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H
#include "string.h"

struct Node {
    struct Node* prev;
    struct Node* next;
    char* val;
    int length;
};

struct DLinkedList {
    struct Node* head;
    struct Node* tail;
    int length;
};

void d_linked_list_insert(struct DLinkedList* l, char* s, int sz);
void d_linked_list_remove(struct DLinkedList* l, int idx);
char** d_linked_list_retrieve(struct DLinkedList* l, int idx, int* sz);
char** d_linked_list_find(struct DLinkedList* l, char** search, int sz);

#endif
