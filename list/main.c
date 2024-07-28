#include "src/list.h"
#include <stdio.h>


int main() {
    List *list = create_list(100);

    for (int i = 'A'; i < 'Z'; ++i) {
        char ch[] = {(char) i, '\0'};
        append(list, ch);
    }

    print_list(list);
    free_list(list);

    return 0;
}