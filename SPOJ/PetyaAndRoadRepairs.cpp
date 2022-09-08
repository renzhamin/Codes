#include <iostream>
#include <set>
#include <algorithm>
#define MAX (int)4e5+5
using namespace std;
int parent[MAX],s[MAX];
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
	long long x,y,c,mcost=0;
	for(int i=0;i<n;++i){
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
	int t,n,m,a,b,k;cin>>t;
	long long w,ans=0;
	while(t--){
		cin>>n>>m;
		bool ismilk[n+1]; k=0;
		for(int i=0;i<=n;i++) parent[i]=i,s[i]=1; 
		for(int i=1;i<=n;i++) {
			cin>>ismilk[i];
			if(ismilk[i])
				nodes[k++]={0,{i,0}};
		}
		for(int i=0;i<m;i++){
			cin>>a>>b>>w;
			nodes[k++]={w,{a,b}};
		} 	
		sort(nodes,nodes+k);
		ans=kruskal(k);
		set<int>milkman;
		for(int i=1;i<=n;i++) if(ismilk[i]) milkman.insert(root(i));
		for(int i=1;i<=n;i++) {
			if(!ismilk[i] && milkman.find(root(i))==milkman.end()){
				cout<<"impossible"<<"\n";
				goto imp;
			}
		}
		cout<<ans<<"\n"; 
		imp:;
	}
}

/*
1
5 7
0 1 0 1 0
1 2 11
1 3 1
1 5 17
2 3 1
3 5 18
4 5 3
2 4 5
*/
