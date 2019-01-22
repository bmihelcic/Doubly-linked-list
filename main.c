#include <stdio.h>
#include "dvostrukopovezana.h"

int main() {
	struct list *listA = NULL;

	init(&listA);

	//upis brojeva od 1 do 10
	for (int i = 1; i < 11; i++) {
		add(&(listA->head), &(listA->tail), i);
	}

	//ispis liste
	print_list(listA->head);

	//brisanje n-tog elementa (6)
	delete(&(listA->head), &(listA->tail), 2);
	print_list(listA->head);	//ispis

	//dodavanje broja 17
	add(&(listA->head), &(listA->tail), 17);
	print_list(listA->head);	//ispis

	//brisanje svih
	deleteAll(&(listA->head), &(listA->tail));
	print_list(listA->head);	//ispis
	print_mid(listA->head);


	return 0;
}

