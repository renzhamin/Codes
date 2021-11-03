#include <bits/stdc++.h>
#define mx 10000
using namespace std;

int arr[mx];	
int tree[mx*3],n;

void init(int node,int b,int e){

    if(b==e){ 
        tree[node]=arr[b];
        arr[b] = node;
        return;
    }

    int left=node*2, right=left+1, mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e,int i,int j){

    if(i>e || j<b) 
        return 0;

    if(b>=i && e<=j) 
        return tree[node];

    int left=node*2, right=left+1, mid=(b+e)/2;
    int p1=query(left,b,mid,i,j),
        p2=query(right,mid+1,e,i,j);

    return p1+p2;

}

void update(int node,int b,int e,int i,int newvalue){

    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[node]=newvalue; //b>=i && e<=i or e==i
        return;
    }

    int left=node*2, right=left+1, mid=(b+e)/2;

    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];

}

void printLeafs(){
    cout<<"( ";
    for(int i=1;i<=n;i++){
        cout<<tree[arr[i]]<<" ";
    } 
    cout<<")\n";
}



int main(){

    int q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];

    init(1,1,n); //initialise tree

    int i,j,v,current;
    while(q--){
        cin>>i>>j; 

        if(i==1){
            cout<<query(1,1,n,j,j)<<" ";
            update(1,1,n,j,0);
            printLeafs();
        } 
        else if(i==2){
                current=query(1,1,n,j,j);
                cin>>v;
                v+=current;
                update(1,1,n,j,v);
                printLeafs();
         } 
        else{
            if(i==3){
                cin>>v; ++v;
                cout<<query(1,1,n,j,v)<<'\n';
            }
        } 
    }
}


/*
   
5 6
3 2 1 4 5
1 5
2 4 4
3 1 4
1 3
3 3 5
1 2

*/
