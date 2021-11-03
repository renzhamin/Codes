#include <bits/stdc++.h>
using namespace std;
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long

struct Node{
    Node *left,*right,*parent;
    ll data,height;
    Node(int k=0):data(k){
        height=0;
        parent=left=right=NULL;
    }
    bool operator < (const Node &b) const{
        return data < b.data;
    }
}*root;

#define height(x) (x?x->height:-1)

void updateHeight(Node *x){
    x->height = 1+max(height(x->left),height(x->right));
}

int balanceFactor(Node *x){
	return height(x->left) - height(x->right);
}

void rightRotate(Node *z){
	Node *y = z->left, *T=y->right, *zp = z->parent;

    y->parent = zp;
    y->right = z;
    z->left = T;

	if (z!=root){
		if (z==zp->right)
			zp->right = y;
		else
			zp->left = y;
    } else {
        root = y;
    }

    z->parent = y;
    updateHeight(y);
    updateHeight(z);
}		


void leftRotate(Node *z){
	Node *y = z->right, *T=y->left, *zp = z->parent;
	y->left = z;
	z->right = T;
	y->parent = zp;
	
	if (z!=root){
		if (z==zp->right)
			zp->right = y;
		else
			zp->left = y;
    } else {
        root = y;
    }
		
	z->parent = y;
    updateHeight(y);
    updateHeight(z);
}		


void balanceNode(Node *z){
	if(z==NULL) return;
	if(balanceFactor(z)>0){
		if(balanceFactor(z->left)>0)
			rightRotate(z);
		else {
			leftRotate(z->left);
			rightRotate(z);;
		};
	} else {
		if(balanceFactor(z->right)<0)
			leftRotate(z);
		else {
			rightRotate(z->right);
			leftRotate(z);
		};
	};
}


Node* updateBST(Node *x){
	Node *imbalanced=NULL;
    bool f=(x->data==15);
	while(x!=root){
        if(x->parent==NULL){
            cout<<x->data<<"\n";
            cout<<"hai"<<"\n";
            return NULL;
        }
        x=x->parent;
		updateHeight(x);
		if (imbalanced==NULL  && abs(balanceFactor(x))>1)
			imbalanced = x;
	};
	return imbalanced;
}

void insert(Node *x){
	if(root==NULL){
		root = x;
		return;
	};
	
	Node *cur=root,*parent;
	
	while(cur){
        parent = cur;
        if(*x<*cur)
            cur=cur->left;
        else
            cur=cur->right;
	}
    x->parent = parent;
	cur = x;
	if(*cur<*parent)
		parent->left = cur;
	else
		parent->right = cur;

	balanceNode(updateBST(cur));
}

void inorder(Node *cur){
    if(cur==NULL) return;
    inorder(cur->left);
    cout<<cur->data<<"("<<balanceFactor(cur)<<") ";
    inorder(cur->right);
}



void levelOrder(){
    queue<Node*>q;
    q.push(root);
    int n,level=1;
    Node *cur;
    while(q.size()){
        n = q.size();
        for(int i=0;i<n;i++){
            cur = q.front(); q.pop();
            cout<<cur->data<<" ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right); 
        } 
        cout<<"\n";
    }
}

void solve(){
    int k; cin>>k;
    while(k!=-1){
        insert(new Node(k));
        cin>>k;
        inorder(root);
        cout<<"\n";
    }
}

bool exists(int k){
    Node *cur=root;
    while(cur){
        if(k<cur->data)
            cur=cur->left;
        else if(k>cur->data)
            cur=cur->right;
        else
            return 1;
    }
    return 0;
}

void takeInput(){
    int k;cin>>k;
    while(k!=-1){
        insert(new Node(k));
        cin>>k;
    }
}

/*
12
8
5
11
20
15
7
1
17
-1
*/
