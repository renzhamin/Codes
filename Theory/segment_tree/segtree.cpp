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

	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];

	init(1,1,n); //initialise tree

	//cout<<query(1,1,7,1,2)<<endl;
	update(1,1,7,2,0);
	cout<<query(1,1,7,2,4)<<endl;	
}