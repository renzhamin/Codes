/*
   CSES Tree Distances II
   https://cses.fi/problemset/result/4600458

   * Find sum of distances for all nodes

   sum ans of all childs
   for the childs sum ans of the parent
   excluding that childs contribution to
   ans of the parent
*/

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 2e5+1;

vector<int>g[N];

ll n;
ll sum[N]; // sum of distances
ll desc[N]; // number of descendents

ll calcDesends(int u, int p=-1){
    ll descends = 0;

    for(auto v:g[u]){
        if(v==p) continue;
        descends += calcDesends(v,u);
    }
    
    desc[u] = descends;
    return descends+1;
}


// calc sum from descendents
ll dfs1(int u, int p=-1){
    ll dist = 0; // sum of dists considering the descendents only

    for(auto v:g[u]){
        if(v==p) continue;
        dist += desc[v] + 1 + dfs1(v,u) ;
        /*
           desc[v] is added because, for all the desc of v 
           the dist of u->desc = v->desc + 1
           1 is added to count distance to v
        */
    }

    return sum[u] = dist;
}


// calc sum from ancestors
void dfs2(int u, int p){
    ll ancs = n - desc[u] - 2; // all nodes excluding parent,u and descs of u

    // contribution of u to p's sum
    ll x = desc[u] + 1 + sum[u];

    // sum for parent excluding subtree of u
    ll y = sum[p] - x;

    // similar logic as calculating from descendents
    sum[u] += ancs + 1 + y;


    for(auto v:g[u]){
        if(v!=p) dfs2(v,u);
        // ans for u is already calculater
        // now calculate ans for v from u
    }
}


int main(){
    int u,v; cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 

    calcDesends(1);
    dfs1(1);
    for(auto v:g[1]) dfs2(v,1);

    for(int i=1;i<=n;++i){
        cout<<sum[i]<<"\n";
    }
}
