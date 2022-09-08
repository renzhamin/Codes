#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct Node{
    Node *left,*right,*parent;
    int x;
    Node(int k=-1){
        x=k;
        left = right = right = NULL;
    }
    
    bool operator < (const Node b) const{
        return x < b.x;
    }
    bool operator > (const Node b) const{
        return x > b.x;
    }

}*root;




void levelOrder(){
    queue<Node*>q;
    q.push(root);
    int n,level=1;
    Node *cur;
    while(q.size()){
        n = q.size();
        for(int i=0;i<n;i++){
            cur = q.front(); q.pop();
            cout<<cur->x<<" ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right); 
        } 
        cout<<"\n";
    }
}

Node* find(Node k){
    Node *cur=root;
    while(cur){
        if(k<*cur)
            cur=cur->left;
        else if(k>*cur)
            cur=cur->right;
        else
            return cur;
    }
    return NULL;
}

void insert(Node *k){
    if(!root){
        root = k;
        return;
    }

    Node *cur,*parent;
    cur=root;
    
    while(cur){
        parent = cur;
        if(*k<*cur)
            cur=cur->left;
        else
            cur=cur->right;
    }
    k->parent = parent;
    if(*k < *parent) parent->left = k;
    else parent->right = k;
}


Node *successor(Node *z){
    Node *cur,*parent;
    if(!z->right){
        if(z==root) return NULL;
        cur = z->parent;
        while(cur!=root){
            if(*cur > *z)
                return cur;
            cur = cur->parent;
        }
        return NULL;
    }
    cur = z->right;
    while(cur->left){
        cur=cur->left;
    }
    return cur;
}

void updateParent(Node *parent,Node *node,Node *value){
    if(!parent) return; //node is root
    if(node==parent->right)
        parent->right=value;
    else
        parent->left=value;
}

bool erase(Node k){
    Node *z = find(k);
    if(!z) return 0;
    
    if(z->left && z->right){
        Node *s=successor(z);

        if(s==z->right){
            s->parent = z->parent;
            s->left = z->left;
            updateParent(z->parent,z,s);
        } 

        else {
            Node *T=s->right;
            updateParent(s->parent,s,T);
            if(T!=NULL) T->parent = s->parent;

            updateParent(z->parent,z,s);
            s->left = z->left;
            s->right = z->right;
        }
        if(z==root) root = s;
    } 

    else if(z->right){
        updateParent(z->parent,z,z->right);
        z->right->parent = z->parent;
        if(z==root) root = z->right;
    } 

    else if(z->left){
        updateParent(z->parent,z,z->left);
        z->left->parent = z->parent;
        if(z==root) root = z->left;
    } 

    else {
        // both child null
        updateParent(z->parent,z,NULL);
    }

    delete(z);
    return 1; 

}
void inorder(Node *cur){
    if(!cur) return;
    inorder(cur->left);
    cout<<cur->x<<" ";
    inorder(cur->right);
}


int main(){
    int k;
    while(cin>>k){
        insert(new Node(k));
    }
    erase(15);
    levelOrder();
}

/*
input
12 9 15
4 3 20 10
11 13 17 18
21 6 5

level Order
12 
9 15 
4 10 13 20 
3 6 11 17 21 
5 18 

*/
