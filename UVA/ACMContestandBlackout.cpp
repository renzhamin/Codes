#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int parent[102],ln[102]; 

int root(int x){
	return (x==parent[x]?x:parent[x]=root(parent[x]));
}

struct edges{
	int from,to,cost;
} arr[5000];


void Union(int a,int b){
	if(ln[b]>ln[a]) swap(a,b);
	parent[b]=a;
	ln[a]+=ln[b];
}

vector<int>taken;

int kruskal(int n,int skip=100000,bool first=1,int k=100){
	int x,y,s=0;
	for(int i=0;i<n;++i){
		if(i==skip) continue;
		x=root(arr[i].from),y=root(arr[i].to);
		if(x==y) continue;
		if(first) taken.emplace_back(i);
		Union(x,y);
		s+=arr[i].cost;
	}

	if(!first){
		int now=root(1);
		for(int i=2;i<=k;i++)
			if(now!=root(i)) 
				return 100000; 
	}

	return s;
}

void reset(){
	memset(ln,1,sizeof(ln));
	iota(parent,parent+102,0);
}

int main(){
	int t,n,m,c1,c2;cin>>t;
	while(t--){
		reset();
		cin>>n>>m;
		for(int i=0;i<m;++i){
			cin>>arr[i].from>>arr[i].to>>arr[i].cost;
		}
		sort(arr,arr+m,[](edges a,edges b){return a.cost<b.cost;});
		c1 = kruskal(m);
		c2=100000;
		for(int i=0;i<taken.size();++i){
			reset();
			c2 = min(c2,kruskal(m,taken[i],0,n));
		}
		cout<<c1<<" "<<c2<<"\n";
		taken.clear();
	}
}
