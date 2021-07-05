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
        int h = node->height;
        h++;
        cout<<"enter left"<<endl;
        Node *leftNode = new_node(key);
        leftNode->left = node;
        leftNode->height = h;
        return leftNode;
    }
    else{
        int h =node->height;
        h++;
        cout<<"enter right:"<<node->height<<endl;
        Node *rightNode = new_node(key);
        rightNode->right =node;
        rightNode->height =h++;;
        return rightNode;
    }
    // we shouldn't reach here
    return nullptr;
}
