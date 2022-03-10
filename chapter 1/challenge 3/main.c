#include "double-link-list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct DLinkedList list;

int main() {
    
    struct Node head;
    list.head = &head;
    list.tail = &head;
    head.prev = 0;

    char* test = (char*) malloc(12*sizeof(char));
    strcpy(test,"Hello World");

    printf("test is %s\n",test);

    free(test);
    return 0;
}
