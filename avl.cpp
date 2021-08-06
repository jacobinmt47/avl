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
/**
 * like insertnb  but balances 
 **/
Node* insert(Node* node, int key){
    if(node == nullptr)
        return new_node(key);
    int b = get_balance(node);
    if(b<1)
        left_rotate(node);
    if(b>-1)
        right_rotate(node);
    insertnb(node,key);
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
Node *right_rotate(Node *n){
    Node *newtop = n->left;
    n->left = newtop->right;
    newtop->right = n;
    n->height = height(n);
    newtop->height = height(newtop);
    return newtop;
}

Node *left_rotate(Node *n){
    cout<<"left rotate"<<endl;
    if(n->right == nullptr)
        cout<<"n right is null"<<endl;
    Node *newtop = n->right;
    n->right = newtop->left;
    newtop->left = n;
    newtop->height = height(newtop);
    n->height = height(n);
    cout<<"end of left rotate"<<endl;
    return newtop;
}

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
