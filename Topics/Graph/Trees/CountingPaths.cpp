/*
   CSES Counting Paths
   https://cses.fi/problemset/task/1136

   Solved using difference array technique
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,level;

vector<vector<ll>> g, up;
vector<ll> tin, tout, cs;

void refersh(){
    g = vector<vector<ll>> ( n+1 );
    tin = tout = cs = vector<ll>(n+1,0);

    level = __lg(n) + 1;
    up = vector<vector<ll>> ( n+1, vector<ll>(level,-1) );
}

void calcAncs(ll u, ll p=-1){
    static ll timer = 0;

    up[u][0] = p;
    
    tin[u] = ++timer;

    for(int i=1; up[u][i-1]!=-1 && i<level; i++){
        up[u][i] = up[ up[u][i-1] ][i-1];
        /* 
            up[u][i] = 2^ith ancestor of u
            up[u][i-1] = 2^(i-1)th ancestor of u
            for example to get 8th ancestor of u we calculate,
            the 4th ancestor of the 4th ancestor of u 
            similary [ 2+2, 4+4, 8+8... ]
        */
    }

    for(auto v:g[u])
        if(v!=p) calcAncs(v,u);

    tout[u] = ++timer;
}

// is u ancestor of v
bool is_ancestor(ll u, ll v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

ll LCA(ll u, ll v){
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    

    for(int i=level-1; i>=0; i--){
        if(up[u][i] == -1) continue;
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}


void dfs(int u,int p=-1){
    for(auto v:g[u]){
        if(v==p) continue;
        dfs(v,u);
        cs[u] += cs[v];
    }
}

int main(){
    ll m;

    cin>>n>>m;
    refersh();

    for(int i=0;i<n-1;i++){
        ll u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 

    calcAncs(1);
    
    while(m--){
        ll a,b;
        cin>>a>>b;
        cs[a]++, cs[b]++;
        ll lca = LCA(a,b);
        cs[lca]--; // reduce extra 1
        if(up[lca][0]!=-1) 
            cs[up[lca][0]]--; // stop 1 from propagating upwards
    }

    dfs(1);

    for(int i=1;i<=n;++i){
        cout<<cs[i]<<" ";
    }
}
