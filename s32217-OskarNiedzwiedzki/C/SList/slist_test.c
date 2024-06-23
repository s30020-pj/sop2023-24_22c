#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

/*testy zostały wygenerowane przez chat gpt*/
/*Sprawdzane jest także, czy łączenie instrukcji (chaining) działa*/
int main() {
    int test_passed = 0;
    int new_value = 100;
    int initial_value = 10;

    /* Test create_slist with initial value */
    struct slist* list = create_slist((void*)&initial_value, sizeof(int));
    printf("Test create_slist with initial value: %s\n", (list != NULL && list->get_size(list) == 1) ? "PASSED" : "FAILED");

    /* Test slist_push_front */
    list = slist_push_front(list, (void*)&test_passed);
    printf("Test slist_push_front: %s\n", (list->get_size(list) == 2) ? "PASSED" : "FAILED");

    /* Test slist_push_back */
    list = slist_push_back(list, (void*)&test_passed);
    printf("Test slist_push_back: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test slist_pop_front */
    list = slist_pop_front(list);
    printf("Test slist_pop_front: %s\n", (list->get_size(list) == 2) ? "PASSED" : "FAILED");

    /* Test slist_pop_back */
    list = slist_pop_back(list);
    printf("Test slist_pop_back: %s\n", (list->get_size(list) == 1) ? "PASSED" : "FAILED");

    /* Test slist_pop */
    list->push_back(list, (void*)&test_passed)->push_back(list, (void*)&test_passed)->push_back(list, (void*)&test_passed); /*chaining instructions*/
    list = slist_pop(list, 1);
    printf("Test slist_pop: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test slist_get_size */
    printf("Test slist_get_size: %s\n", (list->get_size(list) == 3) ? "PASSED" : "FAILED");

    /* Test slist_clear */
    list = slist_clear(list);
    printf("Test slist_clear: %s\n", (list->get_size(list) == 0) ? "PASSED" : "FAILED");

    /* Test slist_get_front */
    list = slist_push_front(list, (void*)&test_passed);
    printf("Test slist_get_front: %s\n", (*(int*)list->get_front(list) == test_passed) ? "PASSED" : "FAILED");

    /* Test slist_get_back */
    list = slist_push_back(list, (void*)&test_passed);
    printf("Test slist_get_back: %s\n", (*(int*)list->get_back(list) == test_passed) ? "PASSED" : "FAILED");

    /* Test slist_get */
    printf("Test slist_get: %s\n", (*(int*)list->get(list, 0) == test_passed) ? "PASSED" : "FAILED");

    /* Test slist_set_front */
    list = slist_set_front(list, (void*)&new_value);
    printf("Test slist_set_front: %s\n", (*(int*)list->get_front(list) == new_value) ? "PASSED" : "FAILED");

    /* Test slist_set_back */
    new_value = 200;
    list = slist_set_back(list, (void*)&new_value);
    printf("Test slist_set_back: %s\n", (*(int*)list->get_back(list) == new_value) ? "PASSED" : "FAILED");

    /* Test slist_set */
    new_value = 300;
    list = slist_set(list, 0, (void*)&new_value);
    printf("Test slist_set: %s\n", (*(int*)list->get(list, 0) == new_value) ? "PASSED" : "FAILED");

    return 0;
}
