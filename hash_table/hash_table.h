/*
Hash Table definition.
char* keys, char* values  
*/
typedef struct Item {
    char* key;
    char* value;
} Item;


void print_item(Item *item);

typedef struct HashTable {
    Item** items;
    int count;
    int capacity;
} HashTable;

HashTable* create_hash_table(int capacity);

Item* get_item(HashTable* table, char* key);

int handle_collision(HashTable *table, Item *item, int index);

int hash_function(HashTable *table, char *key);

int delete_item(HashTable* table, char* key);

int insert_item(HashTable *ht, char *key, char *value);

void print_table(HashTable *table);

void free_table(HashTable *table);

