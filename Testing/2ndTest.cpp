#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define pathtraverse(x) v=sink;while(v!=src){u=par[v];x;v=u;}

struct edge{
    int cap, cost, rev;
    edge(){}
    edge(int cap, int cost) : cap(cap), cost(cost) {}
};

struct mcmf{
    vector<unordered_map<int,int>>mp;
    int src, sink, nodes;
    const int inf = 1e9;
    vector<int> par;
    vector<bool> inq;
    vector<int> dis;
    vector<edge> E;

    mcmf(){}
    mcmf(int src, int sink, int nodes) : src(src), sink(sink), nodes(nodes),
                                         par(nodes), inq(nodes),
                                         dis(nodes),mp(nodes){}

    void addEdge(int u, int v, int cap, int cost, bool directed = true){
        mp[u][v] = E.size();
        E.push_back(edge(cap,cost));
        mp[v][u] = E.size();
        E.push_back(edge(0,-cost));
        if(!directed) addEdge(v, u, cap, cost, true);
    }

    bool spfa(){
        for(int i = 0; i < nodes; i++){
            dis[i] = inf, inq[i] = false;
        }

        queue<int>q;
        q.push(src);
        dis[src] = 0, inq[src] = true, par[src]=-1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            inq[u] = false;
            for(auto [v,ind]:mp[u]){
                edge &e = E[ind];
                if(e.cap < 1) continue;
                if(dis[v] > dis[u] + e.cost){
                    dis[v] = dis[u] + e.cost;
                    par[v] = u;
                    if(!inq[v]) inq[v] = true, q.push(v);
                }
            }
        }

        return (dis[sink] != inf);
    }

    pair<int,int> solve(){
        int mincost = 0, maxflow = 0,u,v,id;
        while(spfa()){
            int bottleneck = inf;

            pathtraverse ( bottleneck=min(bottleneck,E[mp[u][v]].cap) );

            pathtraverse ( id=mp[u][v]; E[id].cap-=bottleneck; E[id^1].cap+=bottleneck);
            

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

