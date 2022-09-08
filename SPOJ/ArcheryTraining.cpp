#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define MAX (int)1e9
using namespace std;
int parent[(int)1e5],s[(int)1e5];
pair<long long,pair<int,int>>nodes[MAX];

int root(int x){
	if(x==parent[x])
		return x;
	return parent[x]=root(parent[x]);
}

void Union(int x,int y){
	if(s[x]>s[y])
		parent[y]=x,s[x]+=s[y];
	else
		parent[x]=y,s[y]+=s[x];
}

long long kruskal(int n){
	int x,y,c,mcost=0;
	for(int i=0;i<=n;++i){
		x=root(nodes[i].second.first);
		y=root(nodes[i].second.second);
		c=nodes[i].first;
		if(x!=y){
			mcost+=c;
			Union(x,y);
		}
	}
	return mcost;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,m,w,a,b;cin>>t;
	long long ans;
	while(t--){
		int k=0;
		cin>>n>>m;
		int parent[n+1],milk[n+1],milkman=0;
		for(int i=0;i<n;i++) parent[i]=i,s[i]=1; 
		for(int i=0;i<n;i++) cin>>milk[i];
		for(int i=0;i<m;i++){
			cin>>a>>b>>w;
			nodes[k++]={w,{a,b}};
		}
		for(int i=0;i<n;i++) if(milk[i]) nodes[k++]={0,{i,0}},milkman++; 	
		sort(nodes,nodes+k);
		ans=kruskal(k);
		cout<<ans<<"\n";
	}
}

