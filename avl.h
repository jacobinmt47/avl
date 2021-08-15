#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include "cpplabs.h"
Node* new_node(int key);
Node* insert(Node* n,int key);
Node* insertnb(Node* node, int key);
Node *left_rotate(Node *x);
Node *right_rotate(Node *x);
int get_balance(Node *x);
int height(Node *n);



#endif // AVL_H_INCLUDED
