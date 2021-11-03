#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e4+1;

unordered_set<int>g[mx];
int n,m,u,v,k,moment,d[mx],low[mx],parent[mx];
vector<pair<int,int>>bridge;

void dfs(int u){
    d[u]=low[u]=moment++;
    for(int v:g[u]){
        if(parent[u]==v) continue; // where it came from
        if(d[v]!=-1){ // backedge
            low[u]=min(low[u],d[v]);
        } else { // new tree edge
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<low[v])
                bridge.emplace_back(u,v);
        }
    }
}

int noNodesinCycle(int s){
    int ans=1;
    queue<int>q;
    bool f=1;
    q.emplace(s); d[s]=1;  // d-> -1 0 1
    while(q.size()){
        u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[v]==-1){
                d[v]=1-d[u];
                q.emplace(v); ans++;
            } else if(d[v]==d[u]) f=0;
        }
    }
    return ans*(!f && ans>=3);
}



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,T=1;cin>>t;
    while(t--){
        memset(d,-1,sizeof(d));
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            g[u].emplace(v);
            g[v].emplace(u);
        }
        for(int i=0;i<n;i++)
            if(d[i]==-1) dfs(i);

        for(auto [u,v]:bridge){
            g[u].erase(v);
            g[v].erase(u);
        }
        memset(d,-1,sizeof(d));
        int ans=0;
        for(int i=0;i<n;i++){
            if(d[i]==-1)
                ans+=noNodesinCycle(i);
            g[i].clear();
        } 
        cout<<"Case "<<T++<<": ";
        cout<<ans<<"\n";
        bridge.clear();
    }
}



/*
1

6 6
0 1
1 2
2 0
3 2
3 4
3 5
*/
