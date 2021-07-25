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
    node->height = height(node)+1;
    //cout<<"node height:"<<node->height<<"  node key:"<<node->key<<endl;
    if(node->key>key){
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
Node *left_rotate(Node *n){
    Node *newtop = nullptr;
    if(n == nullptr)
        return n;

    newtop = n->left;
    newtop->right = n;
    height(newtop);
    return newtop;
}

int get_balance(Node *n){
    if(n == nullptr)
        return 0;
    return height(n->left)-height(n->right);
}
int height(Node *n)
{
    if (n == nullptr)
        return -1;
    if(n->left == nullptr && n->right == nullptr)
        return 0;
    if(n->left != nullptr && n->right != nullptr){
        // return the greatest
        if(n->left->height > n->right->height){
            return height(n->left)+1;
        }
        else{
            return height(n->right)+1;
        }
    }
    if(n->left != nullptr && n->right == nullptr)
        return height(n->left)+1;
    if(n->left == nullptr && n->right != nullptr)
        return height(n->right)+1;

    return 0;
}
