#include <stdio.h>
#include "dvostruka.h"

int main() {
	struct list *listA=NULL;

	init(&listA);

	//upis brojeva od 1 do 10
	for (int i = 1; i <= 10; i++) {
		add(listA, i);
	}
	//ispis liste
	print_list(listA);

	//brisanje n-tog elementa
	delete(listA, 4);
	delete(listA, 7);
	print_list(listA);	//ispis

	//dodavanje broja 17
	add(listA, 17);
	print_list(listA);	//ispis

	//brisanje svih
	deleteAll(listA);
	print_list(listA);	//ispis


	return 0;
}


