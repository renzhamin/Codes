#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct Node{
    Node *left,*right;
    int level,x;
}*root;

int maxHeight=-1;

void Insert(int k){
    if(root==NULL){
        root = new Node();
        root->x = k;
        root->level=0;
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
    cur->level = parent->level+1;
    
    maxHeight = max(maxHeight,cur->level);
}

int main(){
    int k;cin>>k;
    while(k!=-1){
        Insert(k); cin>>k;
    }
    cout<<maxHeight<<"\n";
}
