// MaxFlow_Dinic
// CSES DownloadSpeed
#include <bits/stdc++.h>
#define ll long long 
#define inf INT_MAX
using namespace std;
const int mx=501;
ll n,m,res[mx][mx],u,v,w;
vector<int>g[mx];
int level[mx],nxt[mx],s,e;
bool vis[mx];
 
bool bfs(){
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.emplace(s); level[s]=0;
    while(q.size()){
        u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(level[v]+1 || !res[u][v]) continue;
            level[v]=level[u]+1;
            q.emplace(v);
        }
    }
    return level[e]+1;
}
 
ll dfs(int u,ll minflow){
    if(u==e || !minflow) return minflow;
    for(int &i=nxt[u];i<g[u].size();i++){
        int &v=g[u][i];
        if(level[v]!=level[u]+1 || !res[u][v]) continue;
        ll w = dfs(v,min(minflow,res[u][v]));
        if(!w) continue;
        res[u][v]-=w;res[v][u]+=w;
        return w;
    }
    return 0;
}
 
ll dinic(){
    ll maxflow=0,f=1;
    while(bfs()){
        memset(nxt,0,sizeof(nxt));
        while(f=dfs(s,inf))
            maxflow+=f;
    }
    return maxflow;
}
 
int main(){
    cin>>n>>m;
    s=1,e=n;
    while(m--){
        cin>>u>>v>>w;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        res[u][v]+=w;
    }
    cout<<dinic()<<"\n";
}


/*

4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3

*/
