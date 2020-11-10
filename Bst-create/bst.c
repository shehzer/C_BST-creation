#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BStree  bstree_ini(int size) {
    //dynamically allocate mem of BStree
    BStree bstree = (BStree) malloc(size * sizeof(BStree));
    //allocate mem for node array for tree nodes
    bstree->tree_nodes = malloc(size * sizeof(bstree->tree_nodes));
    //allocate mem for in array for free nodes
    bstree->free_nodes = malloc(size * sizeof(bstree->free_nodes));
    //set mem size to size
    bstree->size = size;
    //set mem top to 1
    bstree->top = 1;
    //set root to 0
    bstree->root = 0;
    //set ea entry of free node to i
    for (size_t index = 0; index < size+1; index++) {
        bstree->free_nodes[index] = index;
    }
    return bstree;
}

static int new_node(BStree b_s_t, Key *key, Data data)
{
    //new variable which carrys top value
    int new_index = b_s_t->top;
    if (new_index < b_s_t->size) {  //if the index is smaller than the tree size
        b_s_t->tree_nodes[new_index].key = key; //new key
        b_s_t->tree_nodes[new_index].data = data; //new data
        b_s_t->tree_nodes[new_index].left = 0; //set its left to 0
        b_s_t->tree_nodes[new_index].right = 0; //its right to 0
        b_s_t->free_nodes[new_index] = 0; //free node
        b_s_t->top++; //increment
        return new_index;
    }
    else {
        printf("%d is out of bounds", new_index);
    }
    // when out of bonds
    return -1;
}
//bst helper function to help insert
static void bst_function(BStree b_s_t, int *index, Key *key, Data data)
{
    Node *binary_root = &b_s_t->tree_nodes[*index];
    int key_comp_value = key_comp(key, binary_root->key);

    if (key_comp_value < 0) {
        // First check if the chararacter array is smaller than current one
        if (binary_root->left != 0) {
            bst_function(b_s_t, &binary_root->left, key, data);
        }
        else {binary_root->left = new_node(b_s_t, key, data);}
    }
    else if (key_comp_value > 0) {
        // Then we have to check if Character array is greater than current one
        if (binary_root->right != 0) {
            bst_function(b_s_t, &binary_root->right, key, data);}
        else {binary_root->right = new_node(b_s_t, key, data);
        }
    }
}
//function that inserts the key and data
void bstree_insert(BStree b_s_t, Key *key, Data data) {
    if (b_s_t->top == 1) //if bst.top ==1
        b_s_t->root = new_node(b_s_t, key, data);
    bst_function(b_s_t, &b_s_t->root, key, data);
}
//define bstree_inorder - encodes in the correct spot
void traversal_inorder(BStree bst, int index){
    if (index == 0) {
        return;
    }
//traverse the left first
    if (bst->tree_nodes[index].left != 0) {
        traversal_inorder(bst, bst->tree_nodes[index].left);
    }
    //then print it
    print_node(bst->tree_nodes[index]);
    //now traverse the right
    if (bst->tree_nodes[index].right != 0) {
        traversal_inorder(bst, bst->tree_nodes[index].right);
    }
}
//traversal of bstree using the inorder function
void bstree_traversal(BStree bst) {
   // int index = bst->root;
    //if(index < bst->size)
        traversal_inorder(bst, bst->root);
}


//function that frees the nodes
void bstree_free(BStree bst) {
    free(bst -> tree_nodes);
    free(bst -> free_nodes);
    free(bst);
}

int ind = *index;
if (ind == 0) {
return;
}
//	Input: ’bst’: a binary search tree
//					’key’:  a Key
//					'index': pointer to current tree node index
//	Effect: delete the tree node who's key is ’key’ from ’bst’
//					if ’key’ is not ’bst’, do nothing
int comp = key_comp(key, bst->tree_nodes[ind].key);
if ( comp < 0 )
bst_delete(bst, &bst->tree_nodes[ind].left, key);
else if ( comp > 0 )
bst_delete(bst, &bst->tree_nodes[ind].right, key);
else { //comp==0
if (bst->tree_nodes[ind].left == 0) {
*index = bst->tree_nodes[ind].right;
}
else if (bst->tree_nodes[ind].right == 0) {
*index = bst->tree_nodes[ind].left;
}
else {
int *index1=&bst->tree_nodes[ind].right;
int ind1 = *index1;
while ( bst->tree_nodes[ind1].left != 0 ) {
index1 = &bst->tree_nodes[ind1].left;
ind1 = *index1;
}
*index1 = bst->tree_nodes[ind1].right;
*index = ind1;
bst->tree_nodes[ind1].left = bst->tree_nodes[ind].left;
bst->tree_nodes[ind1].right = bst->tree_nodes[ind].right;
}
bst->top--;
bst->free_nodes[bst->top] = ind;
}
}

