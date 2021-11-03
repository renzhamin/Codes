#include <iostream>
#define mx 100001
using namespace std;

int arr[mx];	
int tree[mx*3];

void init(int node,int b,int e){

    if(b==e){ 
        tree[node]=arr[b];
        return;
    }

    int left=node*2, right=left+1, mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);

}

int query(int node,int b,int e,int i,int j){

    if(i>e || j<b) 
        return mx;

    if(b>=i && e<=j) 
        return tree[node];

    int left=node*2, right=left+1, mid=(b+e)/2;
    int p1=query(left,b,mid,i,j),
        p2=query(right,mid+1,e,i,j);

    return min(p1,p2);

}

void update(int node,int b,int e,int i,int newvalue){

    if(i>e || i<b)
        return;
    if(b==e){
        tree[node]=newvalue; //b>=i && e<=i or e==i
        return;
    }

    int left=node*2, right=left+1, mid=(b+e)/2;

    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];

}


int main(){

    int n,q,i,j;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);

    while(q--){
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;
    }
}
