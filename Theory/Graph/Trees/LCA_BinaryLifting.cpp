/*
   CSES Company Queries II
   https://cses.fi/problemset/task/1688

   Find LCA using binary-lifting
   https://cp-algorithms.com/graph/lca_binary_lifting.html#implementation
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,level;

vector<vector<ll>> g, up;
vector<ll> tin, tout;

void refersh(){
    g = vector<vector<ll>> ( n+1 );
    tin = vector<ll>(n+1);
    tout = tin;

    level = log2(n) + 3;
    up = vector<vector<ll>> ( n+1, vector<ll>(level,-1) );
}

void calcAncs(ll u, ll p){
    static ll timer = 0;

    up[u][0] = p;
    
    tin[u] = ++timer;

    for(int i=1; up[u][i-1]!=-1 && i<level; i++){
        up[u][i] = up[ up[u][i-1] ][i-1];
        /* 
            up[u][i] = 2^ith ancestor of u
            up[u][i-1] = 2^(i-1)th ancestor of u
            for example to getKthAnc 8th ancestor of u we calculate,
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



int main(){
    ll q;

    cin>>n>>q;
    refersh();

    for(int i=2;i<=n;i++){
        ll u; cin>>u;
        g[u].push_back(i);
    } 

    calcAncs(1, -1);
    
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }
}
