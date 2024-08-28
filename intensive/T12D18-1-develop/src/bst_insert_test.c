#include <stdio.h>

#include "bst.h"
void bst_create_test(struct t_btree** root);
void output_tree(struct t_btree* root, int l);
void bst_insert_test(struct t_btree* root);

int main() {
    struct t_btree* root = bstree_create_node(32);
    bst_insert_test(root);
    return 0;
}

int cmpf(int a, int b) { return a - b; }

void bst_insert_test(struct t_btree* root) {
    int val = 1;
    printf("----------------bst_insert_test-------------\n");
    printf("Test 1: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
    printf("--------------\n");
    val = 43;
    printf("Test 2: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
    printf("--------------\n");
    val = 6;
    printf("Test 3: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
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