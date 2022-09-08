#include <bits/stdc++.h>
#define ll long long 
#define pi pair<int,int>
using namespace std;

const int mx=1000;


int d[mx];

struct node {
    ll V,W;
    bool operator < (const node &a ) const{
        return W>a.W;
    }
};

vector<node>adj[mx];

void djikstra(int start,int n){
    for(int i=0;i<=n;i++) d[i]=1e9;
    priority_queue<node>q;
    q.push({start,0});
    d[start]=0;
    int u,w,v,tmp;
    while(!q.empty()){
        u=q.top().V; w=q.top().W; q.pop();
        for(auto i:adj[u]){
            tmp = w + i.W; v=i.V;
            if(tmp < d[v]){
                d[v] = tmp;
                q.push({v,tmp});
            }
        }
    }
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        int n,m,a,b,w;
        cin>>n>>m;
        while(m--){
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        djikstra(1,n);
        cout<<"Case "<<T++<<": ";
        (d[n]==1e9)?cout<<"Impossible"<<"\n":cout<<d[n]<<"\n";
        for(int i=0;i<n;i++){
            adj[i].clear();
        } 
    }
}

/*
2

 

3 3

1 2 10

1 3 60

2 3 10

 

3 1

1 2 40
*/
