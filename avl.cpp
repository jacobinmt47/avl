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
    cout<<"left rotate"<<endl;
    Node *newtop = new_node(n->right->key);
    newtop->right = n->right->right;
    newtop->left = n;
    newtop->height = (n->height-1);
    n->height = height(n);
    n->left = nullptr;
    n->right = nullptr;
    cout<<"end of left rotate"<<endl;
    return newtop;
}

Node *right_rotate(Node *n){
    cout<<"right rotate"<<endl;
    Node *newtop =new_node(n->left->key);
    newtop->left = n->left->left;
    newtop->right = n;
    newtop->height = (n->height-1);
    n->height = height(n);
    n->left = nullptr;
    n->right = nullptr;
    cout<<"end of right rotate"<<endl;
    return newtop;
}
/**
 * negative if right is greater
 * do left rotate might have this backwards
 **/
int get_balance(Node *n){
    if(n == nullptr)
        return 0;
    int b = height(n->left)-height(n->right);
    return b;
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
