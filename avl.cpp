#include <iostream>
#include "avl.h"

using namespace std;

Node* new_node(int key){
    Node *n = new Node();
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 0;
    return n;
}

Node* insertnb(Node* node, int key){
    if(node == nullptr)
        return new_node(key);
    if(node->key>key){

        cout<<"enter left:"<<node->height<<endl;
        if(node->left == nullptr){
            Node *leftNode = new_node(key);
            node->left = leftNode;
        }
        else{
            insertnb(node->left,key);
        }
        return node;
    }
    else{
        cout<<"enter right:"<<node->height<<endl;
        if(node->right == nullptr){
            Node *rightNode = new_node(key);
            node->right = rightNode;
        }
        else{
            insertnb(node->right,key);
        }
        return node;
    }
    // we shouldn't reach here
    return nullptr;
}
Node *left_rotate(Node *x){
    //got this stuff wrong
    Node *oldtop = x;
    Node *newtop = x->right;
    Node *newRight = x->right->right;
    newtop->left = oldtop;
    oldtop->left = nullptr;
    oldtop->right = nullptr;
    oldtop->height = 2;
    newtop->height = 1;
    newRight->height = 2;
    return newtop;
}

int get_balance(Node *n){
    if(n == nullptr)
        return 0;
    return height(n->left)-height(n->right);
}
int height(Node *N)
{
    if (N == nullptr)
        return -1;
    if(N->left == nullptr && N->right == nullptr)
        return 0;
    
}
