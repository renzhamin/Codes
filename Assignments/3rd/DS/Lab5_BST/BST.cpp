#include <iostream>
#include <stack>
#define ll long long 
using namespace std;

struct Node{
    Node *left,*right;
    int x=-1;
}*root;


bool insert(int k){
    if(root==NULL){
        root = new Node();
        root->x = k;
        return 1;
    }

    Node *cur,*parent;
    cur=parent=root;
    
    while(cur!=NULL){
        parent = cur;
        if(cur->x < k-3)
            cur=cur->right;
        else if(cur->x > k+3)
            cur=cur->left;
        else 
            return 0;
    }

    cur = new Node(); cur->x=k;
    if(k < parent->x) parent->left = cur;
    else parent->right = cur;
    return 1;
}


void Insert(int k){
    if(root==NULL){
        root = new Node();
        root->x = k;
        return;
    }

    Node *cur,*parent;
    cur=root;
    
    while(cur!=NULL){
        parent = cur;
        if(k<=cur->x)
            cur=cur->left;
        else
            cur=cur->right;
    }

    cur = new Node(); cur->x=k;
    if(k <= parent->x) parent->left = cur;
    else parent->right = cur;
}

void inorder(Node *cur){
    inorder(cur->left);
    cout<<cur->x<<" ";
    inorder(cur->right);
}
