#include "list.h"
#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int main() {
    struct door doors[3] = {{0, 0}, {1, 0}, {2, 0}};
    struct node* root = init(&doors[0]);

    // Тест add_door
    add_door(root, &doors[1]);
    if (root->next->door->id != 1) {
        printf("Test add_door: FAIL\n");
        destroy(root);
        return FAIL;
    }
    printf("Test add_door: SUCCESS\n");

    // Тест remove_door
    remove_door(root->next, root);
    if (root->next != NULL && root->next->door->id != 2) {
        printf("Test remove_door: FAIL\n");
        destroy(root);
        return FAIL;
    }
    printf("Test remove_door: SUCCESS\n");

    destroy(root);
    return SUCCESS;
}
