#include "list.h"
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->door = door;
        new_node->next = NULL;
    }
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = init(door);
    if (new_node != NULL) {
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL && current->door->id != door_id) {
        current = current->next;
    }
    return current;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* current = root;
    if (elem == root) {
        root = root->next;
        free(elem);
        return root;
    }
    while (current != NULL && current->next != elem) {
        current = current->next;
    }
    if (current != NULL) {
        current->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* temp = root;
        root = root->next;
        free(temp);
    }
}
