#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void create_list(int capacity) {
    List *_list = NULL;

    _list = (List *) malloc(sizeof(List));
    if (_list == NULL) {
        printf("create_list: error during memory allocation");
        return 1;
    }

    _list->items = NULL;
    _list->items = (list_item **) malloc(capacity * sizeof(list_item*));
    if (_list == NULL) {
        printf("create list_items: error during memory allocation");
        return 1;
    }

    _list->capacity = capacity;
    _list->count = 0;

    return _list;
}


int append(List *list, char *ch) {
    if (list->count >= list->capacity) {
        printf("list full \n");
        return 1;
    }

    list_item *_item = NULL;
    _item = (list_item *) malloc(sizeof(list_item));
    if ()
    
    return 0;
}


void free(List *list) {
    for (int i = 0; i < list->capacity; ++i) {
        if (list->items[i] != NULL) {

            // Free item data and item itself.
            free(list->items[i]->data);
            free(list->items[i]);
        }   
    }

    free(list->items);
    free(list);
}