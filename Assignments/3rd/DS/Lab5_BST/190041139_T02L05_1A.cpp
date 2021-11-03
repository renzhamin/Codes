#include "BST.cpp"
#include <queue>

void levelOrder(){
    queue<Node*>q;
    q.push(root);
    int n,level=1;
    Node *cur;
    while(q.size()){
        cur = q.front(); q.pop();
        cout<<cur->x<<" ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right); 
    }
}

int main(){
    int k;
    bool reserved;
    cin>>k;
    while(k!=-1){
        reserved = insert(k);
        cin>>k;
    }
    levelOrder();
}
