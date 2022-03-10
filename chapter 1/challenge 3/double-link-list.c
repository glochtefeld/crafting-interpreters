#include "double-link-list.h"

void d_linked_list_insert(struct DLinkedList* l, char* s, int sz) {
    struct Node new;
    struct Node* new_p = &new;
    new.val = s;
    new.length = sz;
    new.prev = l->tail;
    l->tail->next = new_p;
    l->tail = new_p;
    l->length++;
}
void d_linked_list_remove(struct DLinkedList* l, int idx);
char** d_linked_list_retrieve(struct DLinkedList* l, int idx, int* sz);
char** d_linked_list_find(struct DLinkedList* l, char** search, int sz);
