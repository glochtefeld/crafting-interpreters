#include "double-link-list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct DLinkedList list = {.length = 0, .head = NULL, .tail = NULL};

void print(struct DLinkedList* l);

int main() {
    d_linked_list_append(&list, "this is a test");
    d_linked_list_append(&list, "hello, world");
    print(&list);

    char* ret = d_linked_list_retrieve(&list, 1);
    if (ret != NULL)
        printf("Value at idx 1 = %s\n", ret);


    bool found = d_linked_list_find(&list, "hello, world");
    bool fnd2 = d_linked_list_find(&list, "Probably not!");
    printf("found = %d, fnd2 = %d\n", found, fnd2);

    int i = list.length - 1;
    while (i >= 0) {
        d_linked_list_remove(&list, i);
        i--;
    }
    return 0;
}

void print(struct DLinkedList* l) {
    if (l->length == 0) {
        printf("[]\n");
        return;
    }

    struct Node* target = l->head;
    printf("[");
    for (int i=0; i<list.length; i++) {
        printf("%s",target->val);
        if (i != l->length - 1)
            printf(", ");
        target = target->next;
    }
    printf("]\n");
}
