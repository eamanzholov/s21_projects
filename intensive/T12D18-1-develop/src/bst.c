#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        if (root->left != NULL) {
            applyf(root->left->val);
        } else {
            printf("null -> ");
        }
        applyf(root->val);
        if (root->right != NULL) {
            applyf(root->right->val);
        } else {
            printf("null -> ");
        }
        printf("\n");
        bstree_apply_infix(root->left, applyf);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->val);
        if (root->left != NULL) {
            applyf(root->left->val);
        } else {
            printf("null -> ");
        }
        if (root->right != NULL) {
            applyf(root->right->val);
        } else {
            printf("null -> ");
        }
        printf("\n");
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        if (root->right != NULL) {
            applyf(root->right->val);
        } else {
            printf("null -> ");
        }
        applyf(root->val);
        if (root->left != NULL) {
            applyf(root->left->val);
        } else {
            printf("null -> ");
        }
        printf("\n");
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
    }
}

struct t_btree *bstree_create_node(int item) {
    struct t_btree *root = (struct t_btree *)malloc(sizeof(struct t_btree));
    root->val = item;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int)) {
    struct t_btree *copy = root;
    struct t_btree *pred = NULL;
    while (copy != NULL) {
        pred = copy;
        if (cmpf(item, copy->val) == 0) {
            return 1;
        }
        if (cmpf(item, copy->val) < 0) {
            copy = copy->left;
        } else {
            copy = copy->right;
        }
    }
    if (pred != NULL) {
        if (cmpf(item, pred->val) < 0) {
            pred->left = bstree_create_node(item);
        } else {
            pred->right = bstree_create_node(item);
        }
    }
    return 0;
}