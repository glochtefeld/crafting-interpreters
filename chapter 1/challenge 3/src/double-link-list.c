#include "double-link-list.h"
#include <stdio.h>

bool d_linked_list_append(struct DLinkedList* l, char* s) {
    struct Node* new = malloc(sizeof *new);
    if (new == NULL)
        return false;

    new->val = malloc(sizeof s);
    strcpy(new->val, s);
    new->prev = l->tail;
    new->next = NULL;

    if (l->length == 0) {
        l->head = new;
        l->tail = new;
        l->length = 1;
    }
    else {
        l->tail->next = new;
        l->tail = new;
        l->length++;
    }
    return true;
}
bool d_linked_list_remove(struct DLinkedList* l, int idx) {
    if (idx >= l->length || idx < 0 || l->head == NULL)
        return false;
    struct Node* target = l->head;
    for (int i=0; i<idx; i++)
        target = target->next;

    if (target == l->head) { // First item
        l->head = target->next;
    } 
    else if (target->next == NULL) { // Last item
        l->tail = target->prev;
    }
    else {
        target->prev->next = target->next;
    }
    l->length--;
    free(target->val);
    free(target);
    return true;
}
char* d_linked_list_retrieve(struct DLinkedList* l, int idx) {
    if (idx > l->length || idx < 0 || l->head == NULL) {
        return NULL;
    }
    struct Node* target = l->head;
    for (int i=0; i<idx; i++)
        target = target->next;
    return target->val;
};
bool d_linked_list_find(struct DLinkedList* l, char* search) {
    bool found = false;

    struct Node* examine = l->head;
    while (examine != NULL && !found) {
        if (strcmp(search, examine->val) == 0)
            found = true;
        else
            examine = examine->next;
    }
    return found;
}
