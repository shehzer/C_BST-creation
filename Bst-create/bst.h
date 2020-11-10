//
// Created by Shehzer Naumani on 2019-11-05.
//

#ifndef ASSIGNMENT_4_BST_H
#define ASSIGNMENT_4_BST_H
#include "data.h"
#endif //ASSIGNMENT_4_BST_H
typedef struct {Node *tree_nodes; unsigned int *free_nodes;
    int size; int top; int root;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, Data data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);