#include <stdio.h>
#include <string.h>

#include "linkedlist.h"


void linkedlist_test();

int main(int argc, char **args)
{
	linkedlist_test();

	return 0;
}

void linkedlist_test()
{
	LinkedList *list = linkedlist_new(sizeof(int));

	printf("List is empty: %d\n", linkedlist_empty(list));
	linkedlist_push(&list, 5);
	linkedlist_push(&list, 10);
	linkedlist_push(&list, 20);

	linkedlist_print(list, linkedlist_print_int); // >> [20, 10, 5]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 3

	linkedlist_popFirst(&list);

	linkedlist_print(list, linkedlist_print_int); // >> [10, 5]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 2

	linkedlist_popLast(&list);
	linkedlist_print(list, linkedlist_print_int); // >> [10]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 1

	linkedlist_popLast(&list);
	linkedlist_print(list, linkedlist_print_int); // >> []
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 0

	linkedlist_push(&list, 24);
	linkedlist_push(&list, 51);

	linkedlist_print(list, linkedlist_print_int); // >> [51, 24]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 2

	linkedlist_clear(&list);
	linkedlist_print(list, linkedlist_print_int); // >> []
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 0

	linkedlist_push(&list, 24);
	linkedlist_push(&list, 51);

	linkedlist_print(list, linkedlist_print_int); // >> [51, 24]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 2

	linkedlist_popLast(&list);
	linkedlist_print(list, linkedlist_print_int); // >> [51]
	printf("Size: %lu\n", linkedlist_size(list)); // >> Size: 1
}
