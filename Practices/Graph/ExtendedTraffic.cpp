#include <bits/stdc++.h>
#define ll long long 
#define pl pair<int,int>
#define ff first
#define ss second
using namespace std;

int n,m,s,de,x,q;
vector<pl>*adj;

const int mx=1000;

ll d[mx],busy[mx];
bool working[mx];

void djikstra(int start,int n){
    memset(working,0,sizeof(working));
    for(int i=0;i<=n;i++) d[i]=1e18;
    priority_queue<pl,vector<pl>,greater<pl>>q;
    q.push({0,start});
    d[start]=0;
    pl u,v;
    while(!q.empty()){
        u=q.top();
        q.pop();
        working[u.second]=1;
        for(int i=0;i<adj[u.second].size();++i){
            v=adj[u.second][i];                //adj[u][i]={cost,node}
            if(working[v.second]) continue;
            if(d[u.second]+v.first<d[v.second]){
                d[v.second]=d[u.second]+v.first;  
                q.push(v);
            }
        }
        working[u.second]=0;
    }
}


int main(){
    int t,T=1;cin>>t;
    while(t--){
        cin>>n;
        vector<pl>arr[n+1];
        for(int i=1;i<=n;i++) cin>>busy[i];
        cin>>m;
        while(m--){
            cin>>s>>de;
            x=busy[de]-busy[s];
            x=x*x*x;
            arr[s].emplace_back(x,de);
            arr[de].emplace_back(-x,s);
        }
        adj=arr;
        djikstra(1,n);
        cin>>q;
        cout<<"Case "<<T++<<":\n";
        while(q--){
            cin>>x;
            if(d[x]<3 || d[x]==1e18){
                cout<<"?"<<"\n";
            } else {
                cout<<d[x]<<"\n";
            }
        }
    }
}
