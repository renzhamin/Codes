#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct Node{
    Node *left,*right;
    int x=-1,
        lsz=0; //left subtree size
}*root;

void insert(int k){
    if(root==NULL){
        root = new Node();
        root->x = k;
        return;
    }
    Node *cur=root,*parent;
    while(cur){
        parent = cur;
        if(k<cur->x){
            cur->lsz++;
            cur=cur->left;
        } else {
            cur=cur->right;
        }
    }

    cur = new Node(); cur->x = k;
    if(k<parent->x)
        parent->left = cur;
    else
        parent->right = cur;
}

int no_of_predecessors(int k){
    Node *cur = root;
    int ans=0;
    while(cur && cur->x!=k){
        if(k<cur->x) cur=cur->left;
        else {
            ans += cur->lsz+1;
            cur = cur->right;
        }
    }
    if(!cur) return -1;
    ans += cur->lsz;
    return ans;
}

int main(){
    int k;cin>>k;
    while(k!=-1){
        insert(k); cin>>k;
    }
    int t;cin>>t;
    while(t--){
        cin>>k;
        cout<<no_of_predecessors(k)<<"\n";
    }
}
