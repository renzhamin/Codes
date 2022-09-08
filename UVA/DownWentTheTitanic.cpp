//Maxflow_nodecap_uva_11380
#include <bits/stdc++.h>
#define ll long long 
#define inf 1e7
using namespace std;
const int mx=1810;
int n,m,res[mx][mx],u,v,maxflow;
vector<int>g[mx];
int s,e,p;
bool vis[mx],f;
#define pathtraverse(x) v=e;while(v!=s){u=parent[v];x;v=u;}


bool flow(int u){
    if(u==e) return 1;
    vis[u]=1;
    for(auto v:g[u]){
        if(vis[v] || !res[u][v]) continue;
        f=flow(v);
        res[u][v]-=f,res[v][u]+=f;
        if(f) return 1;
    }
    return 0;
}

int di[]={0,0,1,-1},
    dj[]={1,-1,0,0};
string grid[35];

void make(int i,int j){
    u=m*i+j,v=u+n*m; //  -->(u-->v)-->
    char &c=grid[i][j];
    if(c=='*')
        g[s].emplace_back(u),res[s][u]=1;
    if(c=='#')
        g[v].emplace_back(e),res[v][e]=p;

    g[u].emplace_back(v);
    g[v].emplace_back(u);
    res[u][v]=(c=='.' || c=='*'?1:inf);
    for(int k=0;k<4;k++){
        int ci=i+di[k],cj=j+dj[k];
        if(ci>=0 && ci<n && cj<m && cj>=0 && grid[ci][cj]!='~'){
            g[v].emplace_back(ci*m+cj);
            g[ci*m+cj].emplace_back(v);
            res[v][ci*m+cj]=inf;
        }
    }
}

int main(){
    while(cin>>n>>m>>p){
        s=2*n*m,e=s+1;
        for(int i=0;i<n;i++) cin>>grid[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='~') make(i,j);
            }
        }
        maxflow=0;
        while(memset(vis,0,sizeof(vis)) && flow(s))
            maxflow++;
        cout<<maxflow<<"\n";
        for(auto &i:g) i.clear(); 
        memset(res,0,sizeof(res));
    }
}


