#include <bits/stdc++.h>
#define ll long long 
#define pi pair<int,int>
using namespace std;

const int mx=1000;

vector<pi>*adj; 

int d[mx];

ll djikstra(int start,int n){
    for(int i=0;i<=n;i++) d[i]=1e9;
    priority_queue<pi,vector<pi>,greater<pi>>q;
    priority_queue<int>sq;
    q.push({0,start});
    d[start]=0;
    pi u,v;
    ll tmp,mn=1e9;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<adj[u.second].size();++i){
            v=adj[u.second][i];                //adj[u][i]={cost,node}
            tmp=d[u.second]+v.first;
            if(tmp<d[v.second]){
                d[v.second]=tmp;
                q.push(v);
            }
            if(v.second==n){
                sq.push(tmp);
            }
        }
    }
    while(sq.size()>2) sq.pop();
    return sq.top();
}


int main(){
    int t,T=1;cin>>t;
    while(t--){
        int n,m,a,b,w;
        cin>>n>>m;
        vector<pi>arr[n+1];
        while(m--){
            cin>>a>>b>>w;
            arr[a].emplace_back(w,b);
            arr[b].emplace_back(w,a);
        }
        adj=arr;
        cout<<"Case "<<T++<<": ";
        cout<<djikstra(1,n)<<"\n"; 
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