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
    bool operator > (const Node &b) const{
        return b.data < data;
    }

}*root;

#define height(x) (x?x->height:-1)

void updateHeight(Node *x){
    x->height = 1+max(height(x->left),height(x->right));
}

int balanceFactor(Node *x){
	return height(x->left) - height(x->right);
}

void updateParent(Node *parent,Node *node,Node *value){
    if(node==parent->right)
        parent->right=value;
    else
        parent->left=value;
}

/*
    zp
    |
    z
   / \
  y  *
 / \
*  T

*/


void rightRotate(Node *z){
	Node *y = z->left, *T=y->right, *zp = z->parent;

    y->parent = zp;
    y->right = z;
    z->left = T;
    if(T) T->parent=z;

	if (z!=root){
        updateParent(zp,z,y);
    } else {
        root = y;
    }

    z->parent = y;
    updateHeight(y);
    updateHeight(z);
}		

/*
   zp
   |
   z
  / \
 *  y
   / \
  T  *

*/

void leftRotate(Node *z){
	Node *y = z->right, *T=y->left, *zp = z->parent;
	y->left = z;
	y->parent = zp;
    z->right = T;
    if(T) T->parent = z;
	
	if (z!=root){
        updateParent(zp,z,y);
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
	if(*x<*parent)
		parent->left = x;
	else
		parent->right = x;

	balanceNode(updateBST(x));
}

void conCheck(Node *x,Node *y){
    if(x==NULL) return;
    conCheck(x->left,x);
    if(x!=root && x->parent!=y){
        cout<<x->data<<"\n";
    }
    conCheck(x->right,x);
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




Node* search(Node k){
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


bool erase(int k){
    Node *cur = search(k);
    if(!cur) return 0;
    int left=2,right=1,child=0;
    if(cur->left) child+=left;
    if(cur->right) child+=right;

    Node *cp = cur->parent;

    if(!child){
        updateParent(cp,cur,NULL);
        delete cur;
        return 1;
    } 
    
    Node *l=cur->left,*r=cur->right;

    if(child==2){
        updateParent(cp,cur,l);
    }
    if(child==1){
        updateParent(cp,cur,r);
    }

    if(child==3){
        Node *pre=l;
        while(pre->right) pre=pre->right;
        if(l!=pre) pre->left = l;
        pre->right =r;
        updateParent(cp,cur,pre);
        Node *T = pre->left;
        updateParent(pre->parent,pre,T);
        pre->parent = cp;
    }

    delete cur;
    return 1;
}

void takeInput(){
    int k;cin>>k;
    while(k!=-1){
        insert(new Node(k));
        cin>>k;
    }
}


int main(){
    takeInput();
    erase(8);
    levelOrder();
//     conCheck(root,NULL);
//     cout<<f->parent->data<<"\n";
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
