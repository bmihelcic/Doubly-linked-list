#ifndef DVOSTRUKA_H_
#define DVOSTRUKA_H_

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
void add(struct list*, int);
void print_list(struct list*);
void delete(struct list*, int);
void deleteAll(struct list*);
void print_mid(struct list*);

#endif


