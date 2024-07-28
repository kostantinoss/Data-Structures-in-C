#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


List *create_list(int capacity) {
    List *_list = NULL;

    _list = (List *) malloc(sizeof(List));
    if (_list == NULL) {
        printf("create_list: error during memory allocation");
        return NULL;
    }

    _list->items = NULL;
    _list->items = (list_item **) malloc(capacity * sizeof(list_item*));
    if (_list == NULL) {
        printf("create list_items: error during memory allocation");
        return NULL;
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
    if (_item == NULL) {
        printf("append: error creating list_item \n");
        return 1;
    }

    // e.g. ch = foo --> strlen: 3
    // but actualy ch = foo\0.
    // We need 3 bytes, + 1 for '\0' delimeter.
    size_t data_len = strlen(ch) + 1;
    
    _item->data = NULL;
    _item->data = (char *) malloc(data_len);
    if (_item->data == NULL) {
        printf("append: error creating list_item \n");
        return 1;
    }

    // Copy data to newly constructed item struct.
    strncpy(_item->data, ch, data_len);

    // Add item to list_items.
    int index = list->count;

    list->items[index] = _item;
    ++(list->count);

    return 0;
}

void print_list(List *list) {
    for (int i = 0; i < list->capacity; ++i) {
        if (list->items[i] != NULL) {
            printf(" %s", list->items[i]->data);
        }
    }
    printf("\n");
}

void free_list(List *list) {
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