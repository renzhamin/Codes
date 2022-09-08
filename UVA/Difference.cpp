#include <bits/stdc++.h>
#define ll long long 
#define MX 600
using namespace std;

int day[MX];
ll v,e,k,a,b,q,T=1,s=0,mn,mx;


void mintime(vector<int>*adj,bool *visited,int now){
	if(visited[now]) return;
	visited[now]=1;
	mn+=day[now];
	for(auto i:adj[now]){
		mintime(adj,visited,i);
	} 
}
void maxtime(vector<int>*adj,bool *visited,int now){
	if(visited[now]) return;
	visited[now]=1;
	mx+=day[now];
	for(auto i:adj[now]){
		maxtime(adj,visited,i);
	} 
}



int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	while(cin>>v>>e && v){
		s=0;
		bool visited[v+1];
		memset(day,0,sizeof(day));
		vector<int>adj[v+1],adj2[v+1];
		for(int i=1;i<=v;i++) {cin>>day[i];s+=day[i];}
		while(e--){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj2[b].emplace_back(a);
		}
		cin>>q;	
		cout<<"Case #"<<T++<<":\n";
		while(q--){
			mn=mx=0;
			cin>>a;
			memset(visited,0,sizeof(visited));
			mintime(adj,visited,a);
			memset(visited,0,sizeof(visited));
			maxtime(adj2,visited,a);
			mx=s-mx+day[a];
			cout<<max(0LL,mx-mn)<<"\n";
		}
		cout<<"\n";
	}
}