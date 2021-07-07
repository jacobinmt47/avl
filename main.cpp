#include <iostream>
#include "avl.h"

using namespace std;

int main(int argc,char** argv){
    Node *root = insertnb(NULL, 10);
    root = insertnb(root, 20);
    root = insertnb(root, 30);
    cout<< root->height<<endl;
    cout<< root->right->height<<endl;
    cout<<root->right->right->height<<endl;
    root = insertnb(NULL, 10);
    root = insertnb(root, 20);
    root = insertnb(root, 30);
    root = left_rotate(root);
    cout<<root->key<<endl;
    cout<<root->left->key<<endl;
    cout<<root->right->key<<endl;
    return 0;
}