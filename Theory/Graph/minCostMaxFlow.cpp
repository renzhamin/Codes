// LightOJ - 1071
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)      for(int i=a;i<=b;i++)

struct edge{
    int v, rev;
    int cap, cost;
    edge(){}
    edge(int v, int rev, int cap, int cost) : v(v), rev(rev), cap(cap), cost(cost){}
};

struct mcmf{
    int src, sink, nodes;
    const int inf = 1e9;
    vector<int> par, idx;
    vector<bool> inq;
    vector<int> dis;
    vector<vector<edge>> g;

    mcmf(){}
    mcmf(int src, int sink, int nodes) : src(src), sink(sink), nodes(nodes),
                                         par(nodes), idx(nodes), inq(nodes),
                                         dis(nodes), g(nodes){}

    void addEdge(int u, int v, int cap, int cost, bool directed = true){
        edge _u(v, g[v].size(), cap, cost);
        edge _v(u, g[u].size(), 0, -cost);
        g[u].push_back(_u);
        g[v].push_back(_v);
        if(!directed) addEdge(v, u, cap, cost, true);
    }

    bool spfa(){
        for(int i = 0; i < nodes; i++){
            dis[i] = inf, inq[i] = false;
        }

        queue<int>q;
        q.push(src);
        dis[src] = 0, par[src] = -1, inq[src] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            inq[u] = false;
            for(int i = 0; i < g[u].size(); i++){
                edge &e = g[u][i];
                if(!e.cap) continue;
                if(dis[e.v] > dis[u] + e.cost){
                    dis[e.v] = dis[u] + e.cost;
                    par[e.v] = u, idx[e.v] = i;
                    if(!inq[e.v]) inq[e.v] = true, q.push(e.v);
                }
            }
        }

        return (dis[sink] != inf);
    }

    pair<int,int> solve(){
        int mincost = 0, maxflow = 0;
        while(spfa()){
            int bottleneck = inf;
            for(int u = par[sink], v = idx[sink]; u != -1; v = idx[u], u = par[u]){
                edge &e = g[u][v];
                bottleneck = min(bottleneck, e.cap);
            }

            for(int u = par[sink], v = idx[sink]; u != -1; v = idx[u], u = par[u]){
                edge &e = g[u][v];
                e.cap -= bottleneck;
                g[e.v][e.rev].cap += bottleneck;
            }

            mincost += bottleneck * dis[sink], maxflow += bottleneck;
        }

        return make_pair(mincost, maxflow);
    }
};

#define in(i,j) ((i-1)*m+j)
#define out(i,j) (in(i,j)+n*m)
int di[2]={0,1},
    dj[2]={1,0};

int main(){
    int t,T=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int source = 1, sink = 2*n*m;
        int arr[n+1][m+1];

        mcmf Flow(source,sink,sink+1);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
                bool f = in(i,j)==source || out(i,j)==sink;
                Flow.addEdge(in(i,j),out(i,j),1+f,-arr[i][j]);
                for(int k=0;k<2;k++){
                    int u = i+di[k], v = j+dj[k];
                    if(u<=n && v<=m){
                        Flow.addEdge(out(i,j),in(u,v),1,0);
                    }
                }
            }
        }
        cout<<"Case "<<T++<<": ";
        cout<<-Flow.solve().first-arr[1][1]-arr[n][m]<<'\n';
    }
}
