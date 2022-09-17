/*
   CSES Company Queries I
   https://cses.fi/problemset/task/1687

   Find Kth ancestor of a node in logn using binary-lifting
   https://youtu.be/oib-XsjFa-M
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,level;

vector<vector<ll>> g, up;

void refersh(){
    g = vector<vector<ll>> ( n+1 );

    level = log2(n) + 3;
    up = vector<vector<ll>> ( n+1, vector<ll>(level,-1) );
}

void calcAncs(ll u, ll p){
    up[u][0] = p;

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
}


ll getKthAnc(ll x, ll k){
    ll u = x; 
    ll cur_level = 0;

    // k = 1011 | 1+2+8 | jump 1,2,8 upward
    while(u!=-1 && cur_level < level){
        if(k&1) u = up[u][cur_level];
        k >>= 1LL;
        cur_level++;
    }
    return u;
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
        ll x,k;
        cin>>x>>k;
        cout<<getKthAnc(x,k)<<"\n";
    }
}
