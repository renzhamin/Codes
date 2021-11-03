#include <iostream>
#include <set>
using namespace std;

int root(int *parent,int i){
	if(parent[i]==i)
		return i;
	return parent[i]=root(parent,parent[i]);
}

void Union(multiset<int>&st,int *parent,int *gs,int *size,int a,int b){
	int x=root(parent,a),
		y=root(parent,b);
	if(x!=y){
		st.erase(st.find(gs[x])),st.erase(st.find(gs[y]));
		if(size[y]>size[x]){
			parent[x]=y,size[y]+=size[x];
			gs[y]+=gs[x],gs[x]=0;
			st.insert(gs[y]);
		}
		else{
			parent[y]=x,size[x]+=size[y];
			gs[x]+=gs[y],gs[y]=0;
			st.insert(gs[x]);
		}
	}
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,m,c1,c2;
	cin>>n>>m;
	multiset<int>st;
	int parent[n+1],size[n+1],groupsize[n+1];
	for(int i=1;i<=n;i++) parent[i]=i,size[i]=1,groupsize[i]=1,st.insert(1);
	for(int i=0;i<m;i++){
		cin>>c1>>c2;
		Union(st,parent,groupsize,size,c1,c2);
		cout<<*st.rbegin()-*st.begin()<<"\n";
	} 
}

/*
5 3
1 2
2 3
5 4
*/