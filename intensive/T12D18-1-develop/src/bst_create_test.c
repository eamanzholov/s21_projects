#include <stdio.h>

#include "bst.h"
void bst_create_test(struct t_btree** root);
void output_tree(struct t_btree* root, int l);

int main() {
    struct t_btree* root = NULL;
    bst_create_test(&root);
    return 0;
}

void bst_create_test(struct t_btree** root) {
    printf("----------------bst_create_test-------------\n");
    int val = 5;
    printf("Test 1: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    *root = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
    val = 123;
    printf("Test 2: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    (*root)->right = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
    val = 2;
    printf("Test 3: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    (*root)->left = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
}

void output_tree(struct t_btree* root, int l) {
    if (root != NULL) {
        output_tree(root->right, l + 1);
        for (int i = 1; i <= 3 * l; i++) {
            printf(" ");
        }
        printf("(%d)\n", root->val);
        output_tree(root->left, l + 1);
    }
}