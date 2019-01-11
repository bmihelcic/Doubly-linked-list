#ifndef DVOSTRUKOPOVEZANA_H_
#define DVOSTRUKOPOVEZANA_H_

struct list {
	struct node* head;
	struct node* tail;
};

struct node {
	int data;
	struct node* prev;
	struct node* next;
};


void init(struct list**);
void add(struct node**, struct node**, int);
void print_list(struct node*);
void delete(struct node**,struct node**, int);

#endif
