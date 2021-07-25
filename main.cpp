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
    
    if(n->right != nullptr){
        printtree(n->right);
    }
}
int main(int argc,char** argv){
   /* Node *root = insertnb(NULL, 20);
    root = insertnb(root, 10);
    root = insertnb(root, 30);
    printtree(root);
    */
    // try a straight tree 10-20-30
    Node *rt2 = insertnb(NULL,10);
    rt2 = insertnb(rt2,20);
    rt2 = insertnb(rt2,30);
    rt2 = insertnb(rt2,40);
    cout<<"-- next tree --"<<endl;
    printtree(rt2);
    return 0;
}