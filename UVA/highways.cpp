#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define mx 100001

struct edges{
	int from,to;
	double dist;
} arr[mx];

int parent[mx],ln[mx];
pair<int,int>co[mx];
vector<pair<int,int>>ans;

int root (int x){
	return x==parent[x]?x:parent[x]=root(parent[x]);
}

void Union(int a,int b){
	if(ln[b]>ln[a]) swap(a,b);
	parent[b]=a;
	ln[a]+=ln[b];
}

void kruskal(int n){
	int x,y;
	for(int i=0;i<n;++i){
		x=root(arr[i].from),y=root(arr[i].to);
		if(x==y) continue;
		Union(x,y);
		ans.emplace_back(arr[i].from+1,arr[i].to+1);
	}
}

int main(){
	int t;cin>>t;
	int n,m,x,y;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>co[i].first>>co[i].second;
			ln[i]=1;
			parent[i]=i;
		}

		cin>>m;
		while(m--){
			cin>>x>>y;
			x--,--y;
			if(root(x)==root(y)) continue;
			Union(parent[x],parent[y]);
		}


		int l=0,dx,dy;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++,++l){
				arr[l].from=i,arr[l].to=j;
				dx=co[i].first-co[j].first,
				dy=co[i].second-co[j].second;
				arr[l].dist = sqrt(dx*dx+dy*dy);
			}
		}

		sort(arr,arr+l,[](edges a,edges b){return a.dist<b.dist;});


		kruskal(l);

		if(!ans.size())
			cout<<"No new highways need"<<"\n";

		for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n"; 

	
		if(t)cout<<"\n";
		ans.clear();
	}	
}
