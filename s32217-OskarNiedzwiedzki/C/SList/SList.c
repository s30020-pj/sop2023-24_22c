#include "SList.h"

struct slist* slist_push_front(struct slist* this, void* val) {
    if (this == NULL)   return NULL;

    this->head = slist_create_node(this->head, val);
    this->size++;
    return this;
}

struct slist* slist_push_back(struct slist* this, void* val) {
    if (this == NULL)    return NULL;
    else if (this->head == NULL) {
        this->head = slist_create_node(NULL, val);
        this->tail = this->head;
        this->size++;
        return this;
    }

    this->tail->next = slist_create_node(NULL, val);
    this->tail = this->tail->next;
    this->size++;
    return this;
}

struct slist* slist_pop_front(struct slist* this) {
    struct slist_node* new_head = NULL;

    if (this == NULL || this->head == NULL)  return NULL;

    new_head = this->head->next;
    free(this->head);
    this->head = new_head;
    this->size--;

    return this;
}

struct slist* slist_pop_back(struct slist* this) {
    struct slist_node* before_tail = NULL;
    if (this == NULL || this->head == NULL) return NULL;

    before_tail = this->head;

    while (before_tail->next != this->tail)
        before_tail = before_tail->next;

    free(before_tail->next);/*delete tail*/
    this->tail = before_tail;
    this->size--;

    return this;
}

int slist_get_size(struct slist* this) {
    return this->size;
}

struct slist* slist_clear(struct slist* this) {
    struct slist_node* next = NULL;
    if (this == NULL || this->head == NULL) return NULL;

    next = this->head->next;
    while (next != NULL) {
        free(this->head);
        this->head = next;
        next = next->next;
    }

    free(this->head);
    this->head = NULL;
    this->size = 0;
    return this;
}

struct slist_node* slist_create_node(struct slist_node* next, void* val)
{
    struct slist_node* out = malloc(sizeof(struct slist_node));
    if (out == NULL) {
        perror("Memory allocation failure!");
        exit(_SLIST_ERROR_MEMORY);
    }

    out->next = next;
    out->val = val;
    return out;
}

struct slist* create_slist(void* val, long data_size) {
    struct slist* out = malloc(sizeof(struct slist));
    if (out == NULL) {
        perror("Memory allocation failure!");
        exit(_SLIST_ERROR_MEMORY);
    }

    out->head = slist_create_node(NULL, val);
    out->tail = out->head;
    out->size = 1;
    out->data_size = data_size;

    /*Init with functions*/
    out->push_front = slist_push_front;
    out->push_back = slist_push_back;
    out->pop_front = slist_pop_front;
    out->pop_back = slist_pop_back;
    out->pop = slist_pop;

    out->get_size = slist_get_size;
    out->clear = slist_clear;

    out->get = slist_get;
    out->get_front = slist_get_front;
    out->get_back = slist_get_back;

    out->set = slist_set;
    out->set_front = slist_set_front;
    out->set_back = slist_set_back;
    /*end init*/

    return out;
}

struct slist* slist_set_front(struct slist* this, void* val){
    if (this == NULL || this->head == NULL) return NULL;
    this->head->val = val;
    return this;
}

struct slist* slist_set_back(struct slist* this, void* val) {
    if (this == NULL || this->tail == NULL) return NULL;
    this->tail->val = val;
    return this;
}

struct slist* slist_set(struct slist* this, int index, void* val) {
    struct slist_node* actual = NULL;
    int iter = 0;
    if (this == NULL || this->tail == NULL) return NULL;
    else if (index < 0 || index >= this->size) return NULL;

    actual = this->head;
    for (iter = 0; iter < index; iter++)
        actual = actual->next;

    actual->val = val;
    return this;
}

void* slist_get_front(struct slist* this) {
    if (this==NULL || this->head == NULL) return NULL;
    return this->head->val;
}

void* slist_get_back(struct slist* this) {
    if (this == NULL || this->head == NULL) return NULL;
    return this->tail->val;
}

void* slist_get(struct slist* this, int index) {
    struct slist_node* actual = NULL;
    int iter = 0;
    if (this == NULL || this->head == NULL) return NULL;
    if (index < 0 || index >= this->size) return NULL;

    actual = this->head;
    for (iter = 0; iter < index; iter++)
        actual = actual->next;

    return actual->val;
}

struct slist* slist_pop(struct slist* this, int index)
{
    struct slist_node* actual = NULL;
    struct slist_node* prev = NULL;
    struct slist_node* next = NULL;
    int iter = 0;
    if (this == NULL || this->tail == NULL) return NULL;
    else if (index < 0 || index >= this->size) return NULL;

    if (index == 0) return slist_pop_front(this);
    else if (index == this->size - 1) return slist_pop_back(this);

    actual = this->head;
    for (iter = 0; iter < index; iter++) {
        prev = actual;
        actual = actual->next;
        next = actual->next;
    }

    free(actual);
    prev->next = next;
    this->size--;

    return this;
}
