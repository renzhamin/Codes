#include "190041139T02L06_1A.cpp"
#define ll long long 
using namespace std;

int lca(int a,int b){
    Node *cur=root;
    while(cur){
        if(cur->data > a && cur->data >b)
            cur = cur->left;
        else if(cur->data <a && cur->data<b)
            cur=cur->right;
        else return cur->data;
    }
    return -1;
}

void task3(){
    int a,b;
    int t;cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
}

int main(){
    takeInput();
    inorder(root);
//     levelOrder();
    task3();
}

/*
12 8 5 11 20 15 7 17 -1
10
5 8
7 12
17 20
7 8
8 7
12 5
12 20
12 17
8 15
11 8
*/
