#include <bits/stdc++.h>
#define ll long long 
#define pi pair<int,int>
using namespace std;

const int mx=6000;

vector<pi>adj[mx]; 

ll d[mx],d2[mx];

ll djikstra(int start,int n){
    for(int i=1;i<=n;i++) d[i]=d2[i]=LLONG_MAX;
    priority_queue<pi>q;
    q.push({0,start});
    d[start]=0;
    pi u,v;
    ll cost;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<adj[u.second].size();++i){
            v=adj[u.second][i];  
            cost=-u.first+v.first;
            if(cost<d[v.second]){
                d2[v.second]=d[v.second];
                d[v.second]=cost;  
                q.push({-d[v.second],v.second});
            } else 
            if(cost<d2[v.second] && cost>d[v.second]){
                d2[v.second]=cost;
                q.push({-d2[v.second],v.second});
            }
        }
    }
    return d2[n];
}

int n,m,a,b,w;
void solve(){
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].emplace_back(w,b);
        adj[b].emplace_back(w,a);

    }
    ll ans=djikstra(1,n);
    cout<<ans<<"\n";
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        cout<<"Case "<<T++<<": ";
        solve();
        for(int i=1;i<=n;i++){
            adj[i].clear();
        } 
    }
}

