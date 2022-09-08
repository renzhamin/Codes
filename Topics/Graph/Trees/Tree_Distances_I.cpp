// https://cses.fi/problemset/task/1132
// CSES Tree Distances I

/*
    Find the two corner nodes while finding diameter
    Now the maximum distance of any node is to one of these two corner nodes
*/


#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,u,v;
vector<vector<int>>adj;
vector<int> max_dist;


ll corner_node;
ll corner_node2;
ll depth = 0; // diameter
 
void dfs(int u, int p=-1, int d=0){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
    }
 
    if(d > depth){
        depth = d;
        corner_node = u;
    }
}


void dfs2(int u,int p=-1,int d=0){
    max_dist[u] = max(max_dist[u], d);
    for(auto v:adj[u]){
        if(v!=p) dfs2(v,u,d+1);
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
 
    cin>>n;
 
    adj = vector<vector<int>>(n+1);
    max_dist = vector<int>(n+1,0);

    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
 
    dfs(1);
    corner_node2 = corner_node;
    depth = 0;
    dfs(corner_node);

    
    dfs2(corner_node);
    dfs2(corner_node2);

    for(int i=1;i<=n;++i){
        cout<<max_dist[i]<<" \n"[i==n];
    }
}
