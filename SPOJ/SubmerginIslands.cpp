//LightOj 1063 - Ant Hills
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e4+1;

vector<int>adj[mx];
int n,m,u,v,moment,art,root,d[mx],low[mx],parent[mx];

void dfs(int u){
    d[u]=low[u]=moment++;
    bool isArtic=0;
    int childs=0;
    for(int v:adj[u]){
        if(parent[u]==v) continue; // where it came from
        if(d[v]!=-1){ // backedge
            low[u]=min(low[u],d[v]);
        } else { // new tree edge
            parent[v]=u; childs++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            isArtic=isArtic || (d[u]<=low[v] && u!=root);
        }
    }
    art+=(isArtic || (u==root && childs>=2));
    adj[u].clear();
}


int main(){
    while(cin>>n>>m && (n+m)){
        art=moment=0;
        memset(d,-1,sizeof(d));
        while(m--){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int i=1;i<=n;++i){
            if(d[i]==-1){
                root=i; dfs(i);
            }
        }
        cout<<art<<"\n";
    }
}

