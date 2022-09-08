#include <iostream>
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
	tree[node]=max(tree[left],tree[right]);

}

int query(int node,int b,int e,int i,int j){

	if(i>e || j<b) 
		return 0;

	if(b>=i && e<=j) 
		return tree[node];

	int left=node*2, right=left+1, mid=(b+e)/2;
	int p1=query(left,b,mid,i,j),
		p2=query(right,mid+1,e,i,j);

	return max(p1,p2);
	
}



int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	int k;cin>>k;
	init(1,1,n);
	int i=1,j=k;
	while(j<=n){
		cout<<query(1,1,n,i,j)<<" ";
		i++;
		j++;
	}

}