#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct edges{
	int from,to;
	double dist;
} arr[284639];

int parent[760],ln[760];
pair<int,int>co[760];
set<int>st;

int root (int x){
	return x==parent[x]?x:parent[x]=root(parent[x]);
}

void Union(int x,int y){
	if(ln[y]>ln[x]) swap(x,y);
	parent[y]=x;
	ln[x]+=ln[y];
	st.erase(y);
}

double kruskal(int n,int group){
	int x,y;
	double s=-1;
	for(int i=0;i<n;++i){
		x=root(arr[i].from),y=root(arr[i].to);
		if(x==y) continue;
		Union(x,y);
		s=max(s,arr[i].dist);
		if(st.size()==group) break;
	}
	return s;
}

int main(){
	int t;cin>>t;
	int n,m,x,y;
	while(t--){
		cin>>m>>n;
		
		for(int i=0;i<n;++i){
			st.emplace(i);
		}

		for(int i=0;i<n;i++) {
			cin>>co[i].first>>co[i].second;
			ln[i]=1;
			parent[i]=i;
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

		cout<<setprecision(2)<<fixed<<kruskal(l,m)<<"\n";

		st.clear();
	}	
}
