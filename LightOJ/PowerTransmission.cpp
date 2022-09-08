// MaxFlow_multi_nodecap
#include <bits/stdc++.h>
#define ll long long 
#define inf LONG_MAX
using namespace std;
const int mx=251;
ll n,m,res[mx][mx],minflow,u,v,w,maxflow;
vector<int>g[mx];
int parent[mx],s,e,b,d;
#define pathtraverse(x) v=e;while(v!=s){u=parent[v];x;v=u;}

bool bfs(){
    memset(parent,0,sizeof(parent));
    queue<int>q;
    q.emplace(s); parent[s]=mx;
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
        cout<<"Case "<<T++<<": ";
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>w;
            g[i].emplace_back(i+n);
            res[i][i+n]=w;
        } 
        cin>>m;
        while(m--){
            cin>>u>>v>>w;
            g[u+n].emplace_back(v);
            g[v].emplace_back(u+n);
            res[u+n][v]=w;
        }
        s=2*n+1,e=s+1;
        cin>>b>>d;
        for(int i=0;i<b;i++){
            cin>>m;
            g[s].emplace_back(m);
            res[s][m]=inf;
        }
        for(int i=0;i<d;i++){
            cin>>m;
            g[m+n].emplace_back(e);
            res[m+n][e]=inf;
        }
        maxflow=0;
        while(bfs());
        cout<<maxflow<<"\n";
        memset(g,0,sizeof(g));
        memset(res,0,sizeof(res));
    }
}
