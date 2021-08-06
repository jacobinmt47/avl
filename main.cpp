#include <iostream>
#include "avl.h"

using namespace std;

void printtree(Node *n){
    //print inorder
    if(n->left != nullptr){
        printtree(n->left);
    }
    cout<<"key: "<<n->key<<endl;
    cout<<"height: "<<n->height<<endl;
    cout<<"balance: "<<get_balance(n)<<endl;
    if(n->right != nullptr){
        printtree(n->right);
    }
}
int main(int argc,char** argv){
/*
    // try a straight tree 10-20-30
    Node *rt2 = insertnb(NULL,10);
    rt2 = insertnb(rt2,20);
    rt2 = insertnb(rt2,30);
    rt2 = left_rotate(rt2);
    printtree(rt2);

    cout<<"next tree"<<endl;
    Node *root = insertnb(NULL,30);
    root = insertnb(root,20);
    root = insertnb(root,5);
    root = insertnb(root,10);
    root = right_rotate(root);
    printtree(root);
    */
    Node *root = insert(NULL, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    return 0;
}
