#include <bits/stdc++.h>
#define ll long long 
#define pi pair<ll,ll>
#define W first
#define V second
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;

const int mx=1000000;

vector<pi>adj[mx]; 

ll d[mx],parent[mx];


void djikstra(int start,int n){
    memset(d,0x7f,sizeof(d));
    priority_queue<pi>q;
    q.push({0,start});
    d[start]=0;
    pi u,v;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<adj[u.V].size();++i){
            v=adj[u.V][i];                //adj[u][i]={cost,node}
            if(d[u.V]+v.W<d[v.V]){
                d[v.V]=d[u.V]+v.W;  
                parent[v.V]=u.V;
                q.push({-d[v.V],v.V});
            }
        }
    }
}

int main(){
    int n,m,a,b,w;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].emplace_back(w,b);
        adj[b].emplace_back(w,a);
    }
    djikstra(1,n);
    if(d[n]==inf){
        cout<<"-1"<<"\n"; return 0;
    }
    vector<int>path;
    int now=n;
    while(now!=1){
        path.emplace_back(now);
        now=parent[now];
    }
    path.emplace_back(1);
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    } 
}


