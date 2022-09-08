// MaxFlow
// CSES DownloadSpeed
#include <bits/stdc++.h>
#define ll long long 
#define inf LONG_MAX
using namespace std;
const int mx=501;
ll n,m,res[mx][mx],minflow,u,v,w,maxflow;
vector<int>g[mx];
int parent[mx],s,e;
#define pathtraverse(x) v=e;while(v!=s){u=parent[v];x;v=u;}

bool flow(){
    memset(parent,0,sizeof(parent));
    queue<int>q;
    q.emplace(s); parent[s]=s;
    bool f=1;
    while(q.size() && f){
        u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(parent[v] || !res[u][v]) continue;
            parent[v]=u;
            if(v==e) {
                f=0; break; 
            }
            q.emplace(v);
        }
    }
    if(f) return 0;
    minflow=inf;
    pathtraverse(minflow=min(minflow,res[u][v]))
    pathtraverse(res[u][v]-=minflow;res[v][u]+=minflow)
    maxflow+=minflow;
    return 1;
}

int main(){
    cin>>n>>m;
    s=1,e=n;
    while(m--){
        cin>>u>>v>>w;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        res[u][v]+=w;
    }
    maxflow=0;
    while(flow());
    cout<<maxflow<<"\n";
}

