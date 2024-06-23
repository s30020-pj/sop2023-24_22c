#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"

/*testy zostały wygenerowane przez chat gpt*/
/*Sprawdzane jest także, czy łączenie instrukcji (chaining) działa*/
int main() {
    int test_passed = 0;
    int new_value = 100;
    int initial_value = 10;

    /* Test create_dlist with initial value */
    struct dlist* list = create_dlist((void*)&initial_value, sizeof(int));
    printf("Test create_dlist with initial value: %s\n", (list != NULL && list->get_size(list) == 1) ? "PASSED" : "FAILED");

    /* Test dlist_push_front */
    list->push_front(list, (void*)&test_passed);
    printf("Test dlist_push_front: %s\n", (list->get_size(list) == 2) ? "PASSED" : "FAILED");

    /* Test dlist_push_back */
    list->push_back(list, (void*)&test_passed);
    printf("Test dlist_push_back: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test dlist_pop_front */
    list->pop_front(list);
    printf("Test dlist_pop_front: %s\n", (list->get_size(list) == 2) ? "PASSED" : "FAILED");

    /* Test dlist_pop_back */
    list->pop_back(list);
    printf("Test dlist_pop_back: %s\n", (list->get_size(list) == 1) ? "PASSED" : "FAILED");

    /* Test dlist_pop */
    list->push_back(list, (void*)&test_passed)->push_back(list, (void*)&test_passed)->push_back(list, (void*)&test_passed); /*chaining instructions*/
    list->pop(list, 1);
    printf("Test dlist_pop: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test dlist_get_size */
    printf("Test dlist_get_size: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test dlist_clear */
    list->clear(list);
    printf("Test dlist_clear: %s\n", (list->get_size(list) == 0) ? "PASSED" : "FAILED");

    /* Test dlist_get_front */
    list->push_front(list, (void*)&test_passed);
    printf("Test dlist_get_front: %s\n", (*(int*)list->get_front(list) == test_passed) ? "PASSED" : "FAILED");

    /* Test dlist_get_back */
    list->push_back(list, (void*)&test_passed);
    printf("Test dlist_get_back: %s\n", (*(int*)list->get_back(list) == test_passed) ? "PASSED" : "FAILED");

    /* Test dlist_get */
    printf("Test dlist_get: %s\n", (*(int*)list->get(list, 0) == test_passed) ? "PASSED" : "FAILED");

    /* Test dlist_set_front */
    list->set_front(list, (void*)&new_value);
    printf("Test dlist_set_front: %s\n", (*(int*)list->get_front(list) == new_value) ? "PASSED" : "FAILED");

    /* Test dlist_set_back */
    new_value = 200;
    list->set_back(list, (void*)&new_value);
    printf("Test dlist_set_back: %s\n", (*(int*)list->get_back(list) == new_value) ? "PASSED" : "FAILED");

    /* Test dlist_set */
    new_value = 300;
    list->set(list, 0, (void*)&new_value);
    printf("Test dlist_set: %s\n", (*(int*)list->get(list, 0) == new_value) ? "PASSED" : "FAILED");

    return 0;
}
