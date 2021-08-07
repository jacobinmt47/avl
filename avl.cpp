#include <iostream>
#include <algorithm>
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
 * calls insertnb but balances first
 **/
Node* insert(Node* node, int key){
    if(node == nullptr)
        return new_node(key);
    int b = get_balance(node);
    if(b>1)
        node = right_rotate(node);
    if(b<-1)
        node = left_rotate(node);
    return insertnb(node,key);
}

Node* insertnb(Node* node, int key){
    if(node == nullptr)
        return new_node(key);
    //node->height = height(node)+1;
    if(node->key>key){
        if(node->left == nullptr){
            Node *leftNode = new_node(key);
            node->left = leftNode;
        }
        else{
             insertnb(node->left,key);
        }
        node->height = height(node);
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
        node->height = height(node);
        return node;
    }
    // we shouldn't reach here
    return nullptr;
}
Node *right_rotate(Node *n){
    cout<<"right rotate"<<endl;
    Node *newtop = n->left;
    if (n->left == nullptr)
        cout<<"left is null ptr"<<endl;
    n->left = newtop->right;
    newtop->right = n;
    newtop->height = height(newtop);
    n->height = height(n);
    return newtop;
}

Node *left_rotate(Node *n){
    cout<<"left rotate"<<endl;
    Node *newtop = n->right;
    if(n->right == nullptr)
        cout<<"n right is null"<<endl;
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
    int lh = height(n->left);
    int rh = height(n->right);
    //cout<<"max height:"<<max(lh,rh)<<"  key:"<<n->key<<endl;
    return  1+max(lh,rh);               
}
