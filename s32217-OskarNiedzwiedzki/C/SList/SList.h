
/*Single node list definitions*/
#ifndef _SLIST_GUARD_
#define _SLIST_GUARD_
#define _SLIST_ERROR_MEMORY 1<<1
#include <stdlib.h> /*malloc extended*/

struct slist*           slist_push_front(struct slist*, void*);
struct slist*           slist_push_back(struct slist*, void*);
struct slist*           slist_pop_front(struct slist*);
struct slist*           slist_pop_back(struct slist*);
struct slist*           slist_pop(struct slist*, int);

int                     slist_get_size(struct slist*);
struct slist*           slist_clear(struct slist*);

/*Utility*/
struct slist_node*      slist_create_node(struct slist_node*, void*);
struct slist*           create_slist(void*,long);

/*Getters*/
void*                   slist_get_front(struct slist*);
void*                   slist_get_back(struct slist*);
void*                   slist_get(struct slist*, int);

/*Setters*/
struct slist*           slist_set_front(struct slist*,void*);
struct slist*           slist_set_back(struct slist*,void*);
struct slist*           slist_set(struct slist*,int,void*);

struct slist_node {
    struct slist_node* next;
    void* val;
};

struct slist {
    struct slist_node* head;
    struct slist_node* tail;
    long size;
    long data_size;

    /*function definitions*/
    struct slist* (*push_front)  (struct slist*, void*);
    struct slist* (*push_back)   (struct slist*, void*);
    struct slist* (*pop_front)   (struct slist*);
    struct slist* (*pop_back)    (struct slist*);
    struct slist* (*pop)         (struct slist*, int);

    int           (*get_size)    (struct slist*);
    struct slist* (*clear)       (struct slist*);

    void* (*get_front)(struct slist*);
    void* (*get_back)(struct slist*);
    void* (*get)(struct slist*,int);
    struct slist*(*set_front)(struct slist*, void*);
    struct slist*(*set_back)(struct slist*,void*);
    struct slist* (*set)(struct slist*,int,void*);

};

#endif