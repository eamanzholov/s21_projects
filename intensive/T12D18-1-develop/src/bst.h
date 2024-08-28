#ifndef BST_H
#define BST_H

struct t_btree {
    int val;
    struct t_btree *left;
    struct t_btree *right;
};

struct t_btree *bstree_create_node(int item);
int bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int));

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int));

#endif