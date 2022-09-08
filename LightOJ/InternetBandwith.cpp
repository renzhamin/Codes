// MaxFlow_Undirected
#include <bits/stdc++.h>
#define ll long long 
#define inf LONG_MAX
using namespace std;
const int mx=101;
ll n,m,res[mx][mx],minflow,u,v,w,maxflow;
vector<int>g[mx];
int parent[mx],s,e;
#define pathtraverse(x) v=e;while(v!=s){u=parent[v];x;v=u;}

bool bfs(){
    memset(parent,0,sizeof(parent));
    queue<int>q;
    q.emplace(s); parent[s]=-1;
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
    pathtraverse(minflow=min(minflow,res[u][v]));
    pathtraverse(res[u][v]-=minflow;res[v][u]+=minflow);
    maxflow+=minflow;
    return 1;
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        memset(res,0,sizeof(res));
        cin>>n>>s>>e>>m;
        while(m--){
            cin>>u>>v>>w;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            res[u][v]+=w;
            res[v][u]+=w;
        }
        maxflow=0;
        while(bfs());
        cout<<"Case "<<T++<<": ";
        cout<<maxflow<<"\n";
        for(int i=1;i<=n;++i){
            g[i].clear();
        }
    }
}

/**
  2
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20


Case 1: 25
Case 2: 40

**/
