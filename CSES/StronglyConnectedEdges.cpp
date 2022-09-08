#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e5+1;

vector<int>g[mx],gr[mx],gu[mx];
bool vis[mx],grey[mx];
stack<int>st;
int u,v,n,m;

void dfs1(int u,int p){
    if(p>0 && (!vis[u] || grey[u])){
        g[p].emplace_back(u);
        gr[u].emplace_back(p);
    }
    if(vis[u]) return;
    vis[u]=1;
    grey[u]=1;
    for(auto v:gu[u]){
        if(v!=p)
            dfs1(v,u);
    }
    grey[u]=0;
}

void dfs2(int u){
    vis[u]=1;
    for(auto v:g[u])
        if(!vis[v]) dfs2(v);
    st.push(u);
}

void dfs3(int u){
    vis[u]=1;
    for(auto v:gr[u])
        if(!vis[v]) dfs3(v);
}

bool scc(){
    memset(vis,0,sizeof(vis));
    int u=st.top(); st.pop();
    dfs3(u);
    for(int i=1;i<=n;++i){
        if(i!=u && !vis[i])
            return 0;
    }
    return 1;
}

int main(){
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        gu[u].emplace_back(v);
        gu[v].emplace_back(u);
    }
    dfs1(1,-1); 
    memset(vis,0,sizeof(vis));
    dfs2(1);
    if(!scc()){
        cout<<"IMPOSSIBLE"<<"\n";
    } else {
        for(int i=1;i<=n;++i){
            for(auto j:g[i])
                cout<<i<<" "<<j<<"\n";
        }
    }
}

