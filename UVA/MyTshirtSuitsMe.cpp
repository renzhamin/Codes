#include <bits/stdc++.h>
#define ll long long 
#define inf LONG_MAX
using namespace std;
unordered_map<string,int>mp={{"S",1},{"M",2},{"L",3},{"XS",4},{"XL",5},{"XXL",6}};
string a;

const int mx=200;
ll n,m,res[mx][mx],minflow,u,v,w,maxflow;
vector<int>g[mx];
int parent[mx],s=0,e=7;
#define pathtraverse(x) v=e;while(v!=s){u=parent[v];x;v=u;}

bool bfs(){
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
    pathtraverse(minflow=min(minflow,res[u][v]));
    pathtraverse(res[u][v]-=minflow;res[v][u]+=minflow);
    maxflow+=minflow;
    return 1;
}


int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m; n/=6;
        for(int i=1;i<=6;i++){
            g[i].emplace_back(e);
            res[i][e]=n;
        }
        for(int i=1;i<=m;++i){
            u=i+e; res[s][u]=1;
            g[s].emplace_back(u);
            for(int j=0;j<2;j++){
                cin>>a; v=mp[a];
                g[u].emplace_back(v);
                g[v].emplace_back(u);
                res[u][v]=1;
            }
        }
        maxflow=0;
        while(bfs());
        cout<<(maxflow>=m?"YES\n":"NO\n");	
        memset(g,0,sizeof(g));
        memset(res,0,sizeof(res));
    }
}
