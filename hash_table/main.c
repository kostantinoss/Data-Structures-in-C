#include <stdio.h>
#include "src/hash_table.h"


int main() {
    HashTable *ht;
    ht = create_hash_table(50);

    for (int i = 'A'; i < 'Z'; ++i) {
        char key[] = {(char) i, '\0'};
        char val[] = "foo";
        insert_item(ht, key, val);
    }

    print_table(ht);
    free_table(ht);

    return 0;
}