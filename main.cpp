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
    Node *root = insertnb(NULL, 20);
    root = insertnb(root, 10);
    root = insertnb(root, 30);
    cout<<"height of root" <<root->height<<endl;
    printtree(root);
    //<<"balance:"<<get_balance(root)<<endl;
    return 0;
}