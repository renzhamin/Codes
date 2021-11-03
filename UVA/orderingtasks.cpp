#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

void dfs(vector<vector<int>>&adj,bool *visited,vector<int>&order,int u){
	for(int i=0;i<adj[u].size();i++){
		if(!visited[adj[u][i]])
			dfs(adj,visited,order,adj[u][i]);
	} 
	visited[u]=1;
	order.push_back(u);
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,e,t1,t2;
	while(cin>>n>>e && n){
		vector<vector<int>>adj(n+1);
		vector<int>order;
		bool visited[n+10];
		for(int i=1;i<=n;i++) visited[i]=0;
		for(int i=0;i<e;i++) cin>>t1>>t2,adj[t1].push_back(t2);
		for(int i=1;i<=n;i++) if(!visited[i]) dfs(adj,visited,order,i);   
		for(int i=order.size()-1;i>=0;i--)
			cout<<order[i]<<" "; 
		cout<<"\n";
	}
}