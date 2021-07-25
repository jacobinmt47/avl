#include "cpplabs.h"
Node* new_node(int key);
void update_height(Node *node);
Node* insertnb(Node* node, int key);
Node *left_rotate(Node *x);
int get_balance(Node *x);
int height(Node *n);
