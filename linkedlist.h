#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>


struct Node {
    struct Node *next;
    void *element;
};

typedef struct {
    struct Node *first;
    struct Node *last;
    size_t elementSize;
    size_t size;
} LinkedList;


LinkedList* linkedlist_new(size_t elementSize);
void linkedlist_push(LinkedList **list, void *element);
void linkedlist_print(const LinkedList *list, void (*f)(void *));
void linkedlist_print_int(void *n);
void linkedlist_popFirst(LinkedList **list);
void linkedlist_popLast(LinkedList **list);
void linkedlist_clear(LinkedList **list);
int linkedlist_empty(const LinkedList *list);
size_t linkedlist_size(const LinkedList *list);


#endif
