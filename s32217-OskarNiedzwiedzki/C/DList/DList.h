
/*Single node list definitions*/
#ifndef _DLIST_GUARD_
#define _DLIST_GUARD_
#define _DLIST_ERROR_MEMORY 1<<1
#include <stdlib.h> /*malloc extended*/

struct dlist* dlist_push_front(struct dlist*, void*);
struct dlist* dlist_push_back(struct dlist*, void*);
struct dlist* dlist_pop_front(struct dlist*);
struct dlist* dlist_pop_back(struct dlist*);
struct dlist* dlist_pop(struct dlist*, int);

int                     dlist_get_size(struct dlist*);
struct dlist* dlist_clear(struct dlist*);

/*Utility*/
struct dlist_node* dlist_create_node(struct dlist_node*, struct dlist_node*, void*);
struct dlist* create_dlist(void*, long);

/*Getters*/
void* dlist_get_front(struct dlist*);
void* dlist_get_back(struct dlist*);
void* dlist_get(struct dlist*, int);

/*Setters*/
struct dlist* dlist_set_front(struct dlist*, void*);
struct dlist* dlist_set_back(struct dlist*, void*);
struct dlist* dlist_set(struct dlist*, int, void*);

struct dlist_node {
	struct dlist_node* next;
	struct dlist_node* prev;
	void* val;
};

struct dlist {
	struct dlist_node* head;
	struct dlist_node* tail;
	long size;
	long data_size;

	/*function definitions*/
	struct dlist* (*push_front)  (struct dlist*, void*);
	struct dlist* (*push_back)   (struct dlist*, void*);
	struct dlist* (*pop_front)   (struct dlist*);
	struct dlist* (*pop_back)    (struct dlist*);
	struct dlist* (*pop)         (struct dlist*, int);

	int           (*get_size)    (struct dlist*);
	struct dlist* (*clear)       (struct dlist*);

	void* (*get_front)(struct dlist*);
	void* (*get_back)(struct dlist*);
	void* (*get)(struct dlist*, int);
	struct dlist* (*set_front)(struct dlist*, void*);
	struct dlist* (*set_back)(struct dlist*, void*);
	struct dlist* (*set)(struct dlist*,int, void*);

};

#endif