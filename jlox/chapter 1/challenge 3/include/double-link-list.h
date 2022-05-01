#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node* prev;
    struct Node* next;
    char* val;
};

struct DLinkedList {
    struct Node* head;
    struct Node* tail;
    int length;
};

bool d_linked_list_append(struct DLinkedList* l, char* s);
bool d_linked_list_remove(struct DLinkedList* l, int idx);
char* d_linked_list_retrieve(struct DLinkedList* l, int idx);
bool d_linked_list_find(struct DLinkedList* l, char* search);

#endif
