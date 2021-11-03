#include <iostream>
#include <stack>
#define ll long long 
using namespace std;

struct Node{
    Node *left,*right,*parent;
    int x=-1,height=0;
}*root;

int height(Node *x){
    return (x?x->height:-1);
}

void updateHeight(Node *cur){
    while(cur!=root){
        cur = cur->parent;
        cur->height = 1+max(height(cur->left),height(cur->right));
    }
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
        if(k<cur->x)
            cur=cur->left;
        else
            cur=cur->right;
    }

    cur = new Node(); cur->x=k; cur->parent=parent;
    if(k <= parent->x) parent->left = cur;
    else parent->right = cur;
    updateHeight(cur);
}

int balance_factor(Node *x){
    return height(x->left)-height(x->right);
}

void inorder(Node *cur){
    if(cur==NULL) return;
    inorder(cur->left);
    cout<<cur->x<<"("<<balance_factor(cur)<<") ";
    inorder(cur->right);
}


int main(){
    int k; cin>>k;
    while(k!=-1){
        Insert(k);
        cin>>k;
        inorder(root);
        cout<<"\n";
    }
}
