/*
   CSES Static Range Sum Queries
   https://cses.fi/problemset/result/4603207/

   LCA using Euler Tour and Sparse Table
   https://cp-algorithms.com/graph/lca.html#implementation
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll UNDEFINED = 0;

const ll N = 4e5+5;
const ll L = 21;

ll dp[N][L], E[N], dE[N], first[N/2];
ll n, tour_length;
vector<vector<int>> g;

bool fn(ll *arr, ll a, ll b){
    return arr[a] < arr[b];
}


void compute_sparse_table(ll *arr, ll n){
    ll level = __lg(n) + 1;

    for(int i=0;i<n;i++) {
        dp[i][0] = i; 
    }

    for(ll k=1; k<=level; k++){
        for(ll i=0; i + ( 1LL << (k-1) )  < n; i++){

            ll left = dp[i][k-1];
            ll right = dp[ i + ( 1LL << (k-1) ) ][k-1];

            dp[i][k] = (fn(arr,left,right)? left:right);
        }
    }
}

ll query(ll l, ll r){
    if(l > r) swap(l,r);
    ll k = __lg(r-l+1);
    ll left = dp[l][k];
    ll right = dp[r - (1LL<<k) + 1][k];
    return (fn(dE,left,right)? E[left]:E[right]);
}


void dfs(int u, int p=-1, int d=0){
    
    first[u] = tour_length;
    dE[tour_length] = d;

    E[tour_length++] = u;
    
    for(auto v:g[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
        
        dE[tour_length] = d;
    
        E[tour_length++] = u;
    }
}

void process(){
    tour_length = 0;
    dfs(1);
    compute_sparse_table(dE, tour_length);
}


int main(){

    ll u,q;
    cin>>n>>q;
    g = vector<vector<int>>(n+1);
    for(int i=2;i<=n;++i){
        cin>>u;
        g[u].push_back(i);
    }

    process();

    while(q--){
        ll l,r; cin>>l>>r;
        cout<<query(first[l],first[r])<<"\n";
    }
}
