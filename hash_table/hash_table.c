/*
Hash Table implementation.
char* keys, char* values  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Item {
    char* key;
    char* value;
} Item;

typedef struct HashTable {
    Item** items;
    int count;
    int capacity;
} HashTable;

HashTable* create_hash_table(int capacity) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->count = 0;
    table->items = (Item**) calloc(capacity, sizeof(Item*));
    table->capacity = capacity;

    for (int i = 0; i < capacity; ++i) {
        table->items[i] = NULL;
    }

    return table;
}

int handle_collision(HashTable *table, Item *item, int index) {
    while (1) {
        if (table->items[index] == NULL) {
            table->items[index] = item;
            table->count++;
            return 1;
        }
        else {
            index = (index + 1) % table->capacity; 
        }
    }

    return 0;
}

int hash_function(HashTable *table, char *key) {
    int i, hash;
    hash = 0;

    for (int i = 0;; ++i) {
        if (key[i] == '\0')
            break;
        hash += key[i];
    }

    return hash % table->capacity;
}
int delete_item(HashTable* table, char* key) {
    int index;
    index = hash_function(table, key);

    if (table->items[index] != NULL) {
        if (strcmp(table->items[index]->key, key) == 0)
            table->items[index] = NULL;
            return 1;
    }

    return 0;
}

int insert_item(HashTable *ht, char *key, char *value) {
    int pos;

    // Check if table is full.
    if (ht->count >= ht->capacity)
        return 0;

    // Create Item.
    Item *item = (Item *) malloc(sizeof(Item));
    item->key = (char *) malloc(sizeof(strlen(key) + 1));
    item->value = (char *) malloc(sizeof(strlen(value) + 1));
    strncpy(item->key, key, strlen(key) + 1);
    strncpy(item->value, value, strlen(key) + 1);

    // Compute index.
    pos = hash_function(ht, key);

    if (ht->items[pos] == NULL) {
        // No collision, insert directly...
        ht->items[pos] = item;
        ht->count ++;
    }
    else {
        if (strcmp(ht->items[pos]->key, key) == 0) {
            // same key, so update key ...
            ht->items[pos]->value = value;
        }
        else {
            // handle collision ...
            return handle_collision(ht, item, pos);
        }
    }

    return 0;
}
void print_item(Item *item) {
    printf("{%s, %s} \n", item->key, item->value);
}

void print_table(HashTable *table) {
    int i;
    
    for (i = 0; i < table->capacity; ++i) {
        if (table->items[i] != NULL)
            printf(" %d. {%s, %s} \n", i, table->items[i]->key, table->items[i]->value);
    }
    printf("count: %d\n", table->count);

}

void free_item(Item *item) {
    free(item->key);
    free(item->value);
    free(item);
}

Item* get_item(HashTable* table, char* key) {
    int index;
    index = hash_function(table, key);
    
    if (table->items[index] != NULL) {
        // Collision ...
        int initial_index = index;
        if (strcmp(table->items[index]->key, key) == 0) {
            return table->items[index];
        } else {
            index = (index + 1) % table->capacity;
            while (1) {
                if (initial_index == index)
                    break;
    
                if (strcmp(table->items[index]->key, key) == 0) {
                    return table->items[index];
                } else {
                    index = (index + 1) % table->capacity;
                }
            }
        }
    }

    return 0;
}

void free_table(HashTable *table) {
    int i;
    for (i = 0; i < table->capacity; ++i) {
        if (table->items[i] != NULL)
            free_item(table->items[i]);
    }
    
    free(table->items);
    free(table);
}
