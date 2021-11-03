//Strongly Connected
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e5+1;

int n,m,scc,S,E;
vector<int>g[mx],gr[mx];
stack<int>st;
bool vis[mx];

void dfs1(int u){
    vis[u]=1;
    for(auto v:g[u])
        if(!vis[v]) dfs1(v);
    st.emplace(u);
}

void dfs2(int u){
    vis[u]=1;
    for(auto v:gr[u])
        if(!vis[v])
            dfs2(v);
}


int main(){
    cin>>n>>m;
    while(m--){
        cin>>S>>E;
        g[S].emplace_back(E);
        gr[E].emplace_back(S);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]) {
            dfs1(i);
        }
    }
    memset(vis,0,sizeof(vis));
    int a=-1,b=-1;
    while(st.size()){
        m=st.top(); st.pop();
        if(!vis[m]){
            if(a+b>=0) b=m;
            if(a==-1) a=m;
            dfs2(m); scc++;
        }
    }
    cout<<(scc<2?"YES\n":"NO\n");	
    if(scc>1){
        cout<<b<<" "<<a<<"\n";
    }
} 

