#include <iostream>
#include "avl.h"

using namespace std;

void printtree(Node *n){
    cout<<n->key<<endl;
    cout<<"height: "<<n->height<<endl;
    if(n->left != nullptr){
        printtree(n->left);
    }
    if(n->right != nullptr){
        printtree(n->right);
    }
}
int main(int argc,char** argv){
    Node *root = insertnb(NULL, 10);
    root = insertnb(root, 20);
    root = insertnb(root, 30);
    cout<< root->height<<endl;
    printtree(root);
    cout <<get_balance(root)<<endl;
    return 0;
}