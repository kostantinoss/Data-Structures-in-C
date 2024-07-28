
typedef struct list_item {
    char *data;
} list_item;

typedef struct List {
    list_item **items;
    int count;
    int capacity;
} List;


/*

*/
List *create_list(int capacity);

/*
Append item to List.
*/
int append(List *list, char *ch);

/*
Return n-th item from List.
*/
int get_item(List *list, char *ch);

/*
Get number of items in list.
*/
int get_item_count(List *list);

/*
Fre allocated memory.
*/
void free(List *list);