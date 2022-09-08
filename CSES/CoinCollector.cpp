#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e5+1;

ll C[mx],fun[mx],fc[mx],dp[mx],cno,n,m,S,E;
vector<int>g[mx],gr[mx];
stack<int>st;
bool vis[mx];
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

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>fun[i];
    }
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
    for(int i=1;i<cno;++i){
        dp[i]=fc[i];
    }
    for(int i=1;i<cno;++i){
        for(auto j:gc[i]){
            dp[j]=max(dp[j],dp[i]+fc[j]);
            ans=max(ans,dp[j]);
        }
    } //or with dfs3
    cout<<ans<<"\n";
}


void dfs3(int u){
    vis[u]=1;
    ll mx=0;
    for(auto v:gc[u]){
        if(!vis[v]){
            dfs3(v);
        }
        mx=max(mx,fc[v]);
    }
    fc[u]+=mx;
    ans=max(ans,fc[u]);
}

