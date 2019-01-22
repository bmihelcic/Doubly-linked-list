#include <stdio.h>
#include <stdlib.h>
#include "dvostrukopovezana.h"

//pocetna funkcija, inicijalizacija liste
void init(struct list** new_list) {
	// zauzimanje memorije za jednu listu, 2 bytea
	*new_list = (struct list*) malloc(sizeof(struct list));
	if (new_list == NULL) {
		printf("Inicijalizacija nije uspjela!\n");
		exit(1);
	}

	// postavi head na NULL
	(*new_list)->head = NULL;
	// postavi tail na NULL
	(*new_list)->tail = NULL;
}

//funkciija za dodavanje elemenata na kraj liste
void add(struct node** headPtr, struct node** tailPtr, int newData) {
	struct node* newNode;
	//zauzimanje memorije za novi cvor
	newNode = (struct node*) malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Neuspjesno zauzimanje memorije za newNode!\n");
		exit(1);
	}
	//upisivanje vrijednosti u novi cvor
	newNode->data = newData;
	//ako je to prvi cvor koji se upisuje
	if ((*headPtr) == NULL && (*tailPtr) == NULL) {
		*headPtr = newNode;	//head pokazuje na novi element
		*tailPtr = newNode; //tail pokazuje na isti novi element
		newNode->prev = NULL;	//prev pokazuje na NULL
		newNode->next = NULL;	//next pokazuje na NULL
		//inace
	} else {
		newNode->next = NULL;		//next novog cvora pokazuje na NULL
		newNode->prev = *tailPtr;//prev novog cvora pokazuje na predzadnji cvor
								 //tail jos nije usmjeren na novi cvor vec pokazuje na predzadnji cvor
		(*tailPtr)->next = newNode;	//next predzadnjeg cvora pokazuje na novi cvor
		*tailPtr = newNode;	//tail pokazuje sada na zadnji, odnosno novo dodani cvor
	}
}

//funkcija za ispis elemenata liste
void print_list(struct node* p) {
	//lista prima pokazivac head, ako je on NULL znaci da nema elemenata u listi
	if (p == NULL) {
		printf("Lista ne sadrzi niti jedan element\n");
		return;
	}
	//ispisuj vrijednosti sve dok pokazivac ne pokazuje na NULL
	do {
		printf("%d ", p->data);
		//pokazivac preusmjeri na sljedeci cvor
		p = p->next;
	} while (p != NULL);
	printf("\n");
}

//funkcija za brisanje n-tog elementa
void delete(struct node** headPtr, struct node** tailPtr, int n) {
	//u slucaju da nema ni jednog cvora u listi, a zeli se izbrisati neki cvor
	if ((*headPtr) == NULL && (*tailPtr) == NULL) {
		printf(
				"Lista ne sadrzi niti jedan element\nNe moze se izvrsiti brisanje %d. cvora\n",
				n);
		return;
	}
	//ako se zeli izbrisati element ciji je redni broj veci nego sto ukupno ima elemenata
	struct node* temp = (*headPtr);
	int br = 0; //brojac koji ce prebrojati koliko ima cvorova
	while (temp != NULL) { //dok temp ne pokazuje na NULL
		br++;	//povecaj brojac
		temp = temp->next;	//preusmjeri temp na sljedeci element
	}
	//npr. ima 2 elementa u listi a korisnik zeli izbrisati 3. element
	if (br < n) {
		printf(
				"\nGreska!\nU listi je %d element%s, a zeli se izbrisati %d. element\n",
				br, (br == 1) ? "" : "a", n);
		return;
	}
	//ako zelimo izbrisati prvi cvor, a u listi se nalazi samo jedan cvor
	if (n == 1 && (*headPtr) == (*tailPtr)) {
		free(*headPtr);		//oslobodi memoriju prvog cvora
		*headPtr = NULL;	//head pokazuje na NULL
		*tailPtr = NULL;	//tail pokazuje na NULL
	}
	//ako zelimo izbrisati prvi cvor, a u listi se nalazi vise od jednog cvora
	else if (n == 1 && (*headPtr) != (*tailPtr)) {
		(*headPtr) = (*headPtr)->next;	//head preusmjeri na sljedeci cvor
		free((*headPtr)->prev);	//preko prev pokazivaca drugog cvora oslobodi memoriju prvog cvora
		(*headPtr)->prev = NULL;//prev pokazivac cvora koji sada postaje prvi u listi preusmjeri na NULL
	}
	//inace, ako zelimo izbrisati neki drugi element
	else {
		temp = (*headPtr);
		for (int i = 1; i < n; i++) {
			temp = temp->next;//neka temp pokazuje na cvor koji zelimo izbrisati
		}
		//ako je cvor koji zelimo izbrisati ujedno i zadnji cvor, odnosno tail
		if (temp == (*tailPtr)) {
			(*tailPtr) = (*tailPtr)->prev;	//tail preusmjeri na predzadnji cvor
			free((*tailPtr)->next);	//oslobodi memoriju koju je zauzimao zadnji cvor
			(*tailPtr)->next = NULL;//next cvora koji postaje zadnji preusmjeri na NULL
		}
		//inace brise se neki cvor izmedju head-a i tail-a
		else {
			temp->prev->next = temp->next; //pokazivac next, cvora prije, preusmjeri na cvor poslije onog kojeg brisemo
			temp->next->prev = temp->prev; //pokazivac prev, cvora poslije, preusmjeri na cvor prije cvora kojeg brisemo
			free(temp);	//oslobodi memoriju koju je zauzimao cvor kojeg brisemo
		}
	}
}

//funkcija za brisanje svih elemenata liste
void deleteAll(struct node** headPtr, struct node** tailPtr) {
	printf("Deleting all\n");
	struct node* temp = *headPtr;
	//kad nema ni jednog elementa, head i tail moraju pokazivati na NULL
	//head ce pokazivati na NULL nakon while petlje
	(*tailPtr) = NULL;
	while ((*headPtr) != NULL) {
		*headPtr = temp->next;	//head postavi na sljedeci node
		free(temp);				//temp pokazuje na node koji treba obrisati, pa pomocu njega oslobađamo memoriju
		temp = *headPtr;		//temp preusmjeri na sljedeci pomocu heada, jer se head u prvom koraku prebacio na sljedeci node
	}
}

//funkcija za ispis elemenata od sredine
void print_mid(struct node* headPtr) {
	int br = 0;	//brojac elemenata
	int i = 0;
	int mid = 0;	//redni broj srednjeg elementa
	struct node* tempL = headPtr;	//pokazivac koji se pomice lijevo
	struct node* tempR = headPtr;	//pokazivac koji se pomice desno
	while (tempL != NULL) {		//dok tempL ne pokazuje na NULL
		br++;					//povecaj brojac
		tempL = tempL->next;	//preusmjeri temp na sljedeci element
	}
	if(br==0){
		printf("Lista ne sadrzi niti jedan element\n");
		return;
	}
	tempL = headPtr;		//temp pokazuje na NULL, pa ga treba vratiti na pocetak
	if (br % 2 == 0) {	//ako je broj elemenata u listi paran, ovo ce se "izvrtiti"
		printf("\nPrinting from mid:\nBroj elemenata je paran\n");
		mid = br / 2;		//kad je paran broj elemenata, za srednji se uzima onaj cvor blize pocetku
		for (i = 1; i < mid; i++) {
			tempL = (tempL->next);		//postavljanje tempL na srednji node
		}
		tempR = tempL->next;		//postavljanje tempR na node desno od tempL
		while (tempL != NULL) {		//dok tempL nije NULL
			printf("%d %d ", tempL->data, tempR->data);		//ispis
			tempL = tempL->prev;	//pomakni tempL lijevo
			tempR = tempR->next;	//pomakni tempL desno
		}
	}
	else	// ovo ce se izvrsiti ako je u listi neparan broj elemenata
	{
		printf("\nPrinting from mid:\nBroj elemenata je neparan\n");
		/*
		 * ako je npr broj elemenata 9, kad podijelimo s 2 dobit cemo da je mid 4
		 * jer int uzima cjelobrojni rezultat od 4.5
		 * sredisnji node je ustvari 5., zato dodajemo 1
		 */
		mid = ((br / 2)+1);
		for (i = 1; i < mid; i++)
		{
			tempL = (tempL->next);		//pomici tempL do sredine
		}
		tempR = tempL->next;	//tempR je prvi desno
		while (tempR != NULL)  	//tempR ce prvi pokazivati na NULL pa gledamo njega
		{
			printf("%d %d ", tempL->data, tempR->data);
			tempL = tempL->prev;	//pomakni tempL u lijevo
			tempR = tempR->next;	//pomakni tempR u desno
		}
		printf("%d\n",tempL->data);	//ispisi jos samo prvi element
	}
}

