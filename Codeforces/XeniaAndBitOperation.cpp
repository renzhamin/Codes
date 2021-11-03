#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=1e6;
ll n,m;
int tree[mx*4],level,arr[mx],ind,b;


void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left=node*2,right=left+1,mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    level=log2(node);
    if((abs(n-level)&1))
        tree[node]=tree[left] | tree[right];
    else
        tree[node]=tree[left] ^ tree[right];
}

void update(int node,int b,int e,int i,int newvalue){

    if(i>e || i<b)
        return;
    if(b==e){
        tree[node]=newvalue; 
        return;
    }

    int left=node*2, right=left+1, mid=(b+e)/2;

    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    level=log2(node);
    if((abs(n-level)&1))
        tree[node]=tree[left] | tree[right];
    else
        tree[node]=tree[left] ^ tree[right];

}


int main(){
    cin>>n>>m;
    int N=1<<n;
    for(int i=0;i<N;i++) cin>>arr[i+1];
    init(1,1,N);
    while(m--){
        cin>>ind>>b;
        update(1,1,N,ind,b);
        cout<<tree[1]<<"\n";
    }
}








