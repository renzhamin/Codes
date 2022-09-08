#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,u,v;
vector<vector<int>>adj;
 
ll corner_node = 0;
ll depth = 0;
 
void dfs(int u, int p=0, int d=0){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
    }
 
    if(d > depth){
        depth = d;
        corner_node = u;
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
 
    cin>>n;
 
    adj = vector<vector<int>>(n+1);
 
 
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
 
    dfs(1);
    dfs(corner_node);
    cout<<depth<<"\n";
}
