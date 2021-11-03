#include <iostream>
#include <cstdlib>
#define scan(a) scanf("%d",&a);
#define print(a) printf("%d\n",a);
#define mx 300000
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
	if(b>=i && e<=i){
		tree[node]=newvalue; //b>=i && e<=i or e==i
		return;
	}

	int left=node*2, right=left+1, mid=(b+e)/2;

	update(left,b,mid,i,newvalue);
	update(right,mid+1,e,i,newvalue);
	tree[node]=tree[left]+tree[right];

}



int main(){

	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	
	int t;scan(t);
	for(int p=1;p<=t;p++){
		int n,q;cin>>n>>q;
		for(int i=1;i<=n;i++) scan(arr[i]);

		init(1,1,n); //initialise tree

		printf("Case %d:\n",p);
		int i,j,v,current;
		while(q--){
			scanf("%d%d",&i,&j); j++;
			if(i==1){
				print(query(1,1,n,j,j));
				update(1,1,n,j,0);
			} else 
			if(i==2){
				current=query(1,1,n,j,j);
				scan(v)
				v+=current;
				update(1,1,n,j,v);
			} else 
			if(i==3){
				scan(v) ++v;
				print(query(1,1,n,j,v));
			}
		}
	}
}