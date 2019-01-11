#include <stdio.h>
#include "dvostrukopovezana.h"

int main() {
	struct list *listA = NULL;

	init(&listA);

	for(int i=1;i<21;i++){
		add(&(listA->head), &(listA->tail), i);
	}

	printf("ListA: ");
	print_list(listA->head);

	delete(&(listA->head),&(listA->tail),6);
	printf("\nListA: ");
	print_list(listA->head);

	add(&(listA->head), &(listA->tail), 125);
	printf("\nListA: ");

	print_list(listA->head);

	return 0;
}
