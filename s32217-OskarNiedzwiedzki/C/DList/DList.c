#include "DList.h"

struct dlist* dlist_push_front(struct dlist* this, void* val) {
    if (this == NULL)   return NULL;

    this->head = dlist_create_node(this->head,NULL, val);
    this->head->next->prev = this->head;
    this->size++;
    return this;
}

struct dlist* dlist_push_back(struct dlist* this, void* val) {
    if (this == NULL)    return NULL;
    else if (this->head == NULL) {
        this->head = dlist_create_node(NULL,NULL, val);
        this->tail = this->head;
        this->size++;
        return this;
    }

    this->tail->next = dlist_create_node(NULL,this->tail, val);
    this->tail->next->prev = this->tail;
    this->tail = this->tail->next;
    this->size++;
    return this;
}

struct dlist* dlist_pop_front(struct dlist* this) {
    struct dlist_node* new_head = NULL;

    if (this == NULL || this->head == NULL)  return NULL;

    new_head = this->head->next;
    free(this->head);
    this->head = new_head;
    this->head->prev = NULL;
    this->size--;

    return this;
}

struct dlist* dlist_pop_back(struct dlist* this) {
    struct dlist_node* before_tail = NULL;
    if (this == NULL || this->head == NULL) return NULL;

    this->tail = this->tail->prev;
    free(this->tail->next);
    this->size--;

    return this;
}

int dlist_get_size(struct dlist* this) {
    return this->size;
}

struct dlist* dlist_clear(struct dlist* this) {
    struct dlist_node* next = NULL;
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

struct dlist_node* dlist_create_node(struct dlist_node* next, struct dlist_node* prev, void* val)
{
    struct dlist_node* out = malloc(sizeof(struct dlist_node));
    if (out == NULL) {
        perror("Memory allocation failure!");
        exit(_DLIST_ERROR_MEMORY);
    }

    out->next = next;
    out->prev = prev;
    out->val = val;
    return out;
}

struct dlist* create_dlist(void* val, long data_size) {
    struct dlist* out = malloc(sizeof(struct dlist));
    if (out == NULL) {
        perror("Memory allocation failure!");
        exit(_DLIST_ERROR_MEMORY);
    }

    out->head = dlist_create_node(NULL,NULL, val);
    out->tail = out->head;
    out->size = 1;
    out->data_size = data_size;

    /*Init with functions*/
    out->push_front = dlist_push_front;
    out->push_back = dlist_push_back;
    out->pop_front = dlist_pop_front;
    out->pop_back = dlist_pop_back;
    out->pop = dlist_pop;

    out->get_size = dlist_get_size;
    out->clear = dlist_clear;

    out->get = dlist_get;
    out->get_front = dlist_get_front;
    out->get_back = dlist_get_back;

    out->set = dlist_set;
    out->set_front = dlist_set_front;
    out->set_back = dlist_set_back;
    /*end init*/

    return out;
}

struct dlist* dlist_set_front(struct dlist* this, void* val) {
    if (this == NULL || this->head == NULL) return NULL;
    this->head->val = val;
    return this;
}

struct dlist* dlist_set_back(struct dlist* this, void* val) {
    if (this == NULL || this->tail == NULL) return NULL;
    this->tail->val = val;
    return this;
}

struct dlist* dlist_set(struct dlist* this, int index, void* val) {
    struct dlist_node* actual = NULL;
    int iter = 0;
    if (this == NULL || this->tail == NULL) return NULL;
    else if (index < 0 || index >= this->size) return NULL;

    /*if set value is on the left side, iterate from head, otherwise from tail*/
    if (index < this->size / 2) {
        actual = this->head;
        for (iter = 0; iter < index; iter++)
            actual = actual->next;

        actual->val = val;
    }
    else {
        actual = this->tail;
        for (iter = 0; iter < this->size - index; iter++)
            actual = actual->prev;

        actual->val = val;
    }

    return this;
}

void* dlist_get_front(struct dlist* this) {
    if (this == NULL || this->head == NULL) return NULL;
    return this->head->val;
}

void* dlist_get_back(struct dlist* this) {
    if (this == NULL || this->head == NULL) return NULL;
    return this->tail->val;
}

void* dlist_get(struct dlist* this, int index) {
    struct dlist_node* actual = NULL;
    int iter = 0;
    if (this == NULL || this->head == NULL) return NULL;
    if (index < 0 || index >= this->size) return NULL;

    /*if set value is on the left side, iterate from head, otherwise from tail*/
    if (index < this->size / 2) {
        actual = this->head;
        for (iter = 0; iter < index; iter++)
            actual = actual->next;
    }
    else {
        actual = this->tail;
        for (iter = 0; iter < (this->size - index)-1; iter++)
            actual = actual->prev;
    }

    return actual->val;
}

struct dlist* dlist_pop(struct dlist* this, int index)
{
    struct dlist_node* actual = NULL;
    int iter = 0;
    if (this == NULL || this->tail == NULL) return NULL;
    else if (index < 0 || index >= this->size) return NULL;

    if (index == 0) return dlist_pop_front(this);
    else if (index == this->size - 1) return dlist_pop_back(this);

    /*if set value is on the left side, iterate from head, otherwise from tail*/
    if (index < this->size / 2) {
        actual = this->head;
        for (iter = 0; iter < index; iter++)
            actual = actual->next;
    }
    else {
        actual = this->tail;
        for (iter = 0; iter < this->size - index; iter++)
            actual = actual->prev;
    }

    actual->prev->next = actual->next;
    actual->next->prev = actual->prev;
    free(actual);
    this->size--;

    return this;
}
