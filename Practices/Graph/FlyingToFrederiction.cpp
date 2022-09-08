// uva 11280
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=101;
#define inf INT_MAX

unordered_map<string,int>mp;
ll d[mx][mx],n,m,q,u,v,w,e,tmp;

struct edge{
    ll V,W,E;
    bool operator < ( const edge &a ) const{
        return a.W < W;
    }
};

vector<edge>adj[mx];

void djikstra(int start){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            d[i][j]=inf;
        }
    }
    priority_queue<edge>q;
    q.push({start,0,0});
    d[start][0]=0;
    while(!q.empty()){
        u = q.top().V;
        w = q.top().W;
        e = q.top().E;
        q.pop();
        for(auto i:adj[u]){
            v=i.V;
            tmp = w + i.W;
            if(tmp < d[v][e]){
                d[v][e] = tmp;
                q.push({v,tmp,e+1});
            }
        }
    }
}

string us,vs;

int main(){
    int t,T=1;cin>>t;
    while(t--){
        if(T!=1) cout<<"\n";
        cout<<"Scenario #"<<T++<<"\n";
        cin>>n;
        ll cost[n];
        for(int i=1;i<=n;i++){
            cin>>us; mp[us]=i;
        } 
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>us>>vs>>w;
            adj[mp[us]].push_back({mp[vs],w});
        }
        djikstra(1); 
        cost[0]=d[n][0];
        for(int i=1;i<n;i++){
            cost[i]=min(cost[i-1],d[n][i]);
        } 
        cin>>q;
        while(q--){
            cin>>m;
            if(m>=n) m=n-1;
            ll &c = cost[m];
            if(c==inf)
                cout<<"No satisfactory flights"<<"\n";
            else
                cout<<"Total cost of flight(s) is $"<<c<<"\n";
        }
        for(int i=0;i<n;i++){
            adj[i].clear();
        } 
        mp.clear();
    }
}
