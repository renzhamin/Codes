#include <bits/stdc++.h>
#define mx 10001
using namespace std;

struct info {
    int prop=0, sum=0;
} tree[mx * 3]; 


int arr[] = {0,1,2,3,4,5,6,7,8,9,10};

void init(int node,int b,int e){
	
	if(b==e){ 
		tree[node].sum=arr[b];
		return;
	}

	int left=node*2, right=left+1, mid=(b+e)/2;

	init(left,b,mid);
	init(right,mid+1,e);
	tree[node].sum=tree[left].sum+tree[right].sum;
}


void update(int node, int b, int e, int i, int j, int x){
    if (i > e || j < b)
        return;
    
    if (b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x; 
        return;
    }

    int Left = node << 1,Right = Left + 1,mid = (b + e) >> 1;
    
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}


int query(int node, int b, int e, int i, int j, int carry = 0){
    
    if (i > e || j < b)
        return 0;

    if (b >= i && e <= j)
        return tree[node].sum + carry * (e - b + 1); 

    int Left = node << 1,Right = Left + 1,mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop); 
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main(){

    int n = sizeof(arr)/sizeof(arr[0])-1;

    init(1,1,n);

    update(1,1,n,4,6,-4);

    cout<<query(1,1,n,1,n)<<'\n';

}
