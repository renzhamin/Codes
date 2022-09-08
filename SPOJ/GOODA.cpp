#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e6+1;

int C[mx],fun[mx],fc[mx],cno,n,m,s,e,S,E;
vector<int>g[mx],gr[mx];
stack<int>st;
bool vis[mx],cvis[mx];
ll ans;
unordered_map<int,unordered_set<int>>gc;

void dfs1(int u){
    vis[u]=1;
    for(auto v:g[u])
        if(!vis[v]) dfs1(v);
    st.push(u);
}

void dfs2(int u){
    vis[u]=1;
    C[u]=cno;
    fc[cno]+=fun[u];
    if(u==s) S=cno;
    if(u==e) E=cno;
    for(auto v:gr[u])
        if(!vis[v])
            dfs2(v);
}

void creategc(){
    for(int i=1;i<=n;++i){
        for(auto j:g[i]){
            if(C[i]!=C[j]){
                gc[C[i]].emplace(C[j]);
            }
        }
    }
}

void dfs3(int u,ll cost){
    if(u==E) ans=max(ans,cost);
    vis[u]=1;
    for(auto v:gc[u]){
        if(!vis[v])
            dfs3(v,cost+fc[v]);
    }
}


int main(){
    cin>>n>>m>>s>>e;
    for(int i=1;i<=n;i++) cin>>fun[i];
    while(m--){
        cin>>S>>E;
        g[S].emplace_back(E);
        gr[E].emplace_back(S);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]) dfs1(i);
    }
    cno=1;
    memset(vis,0,sizeof(vis));
    while(!st.empty()){
        m=st.top(); st.pop();
        if(!vis[m]){
            dfs2(m); cno++;
        }
    }
    creategc();
    ans=-1;
    memset(vis,0,sizeof(vis));
    dfs3(S,fc[S]);
    cout<<ans<<"\n";
}

