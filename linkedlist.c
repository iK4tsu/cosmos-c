#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linkedlist.h"


LinkedList* linkedlist_new(size_t elementsSize)
{
	LinkedList *newlist = malloc(sizeof(LinkedList));
	newlist->elementSize = elementsSize;
	newlist->size = 0;
	newlist->last = newlist->first;
	return newlist;
}

void linkedlist_push(LinkedList **list, void *element)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->next = (*list)->first;
	newNode->element = element;
	(*list)->size++;
	(*list)->first = newNode;
}

void linkedlist_popFirst(LinkedList **list)
{
	assert(!linkedlist_empty(*list));
	struct Node *nodeAux = (*list)->first;
	(*list)->first = nodeAux->next;
	free(nodeAux);

	if ((*list)->size == 1)
		(*list)->first == NULL;

	(*list)->size--;
}

void linkedlist_popLast(LinkedList **list)
{
	assert(!linkedlist_empty(*list));
	struct Node *nodeAux = (*list)->first;
	int i = 1;
	for (; i < (*list)->size - 1; i++)
		nodeAux = nodeAux->next;

	free((*list)->last);

	if ((*list)->size == 1)
		(*list)->first = NULL;
	else
	{
		(*list)->last = nodeAux;
		nodeAux->next = NULL;
	}

	(*list)->size--;
}

void linkedlist_clear(LinkedList **list)
{
	while ((*list)->first != NULL) {
		linkedlist_popFirst(list);
	}
}

void linkedlist_print(const LinkedList *list, void (*f)(void *))
{
	struct Node *node = list->first;

	printf("[");
	while (node != NULL)
	{
		f(node->element);
		node = node->next;

		if (node != NULL) printf(", ");
	}
	printf("]\n");
}

void linkedlist_print_int(void *n)
{
	printf("%d", (int *)n);
}

int linkedlist_empty(const LinkedList *list)
{
	return list->size == 0;
}

size_t linkedlist_size(const LinkedList *list)
{
	return list->size;
}
