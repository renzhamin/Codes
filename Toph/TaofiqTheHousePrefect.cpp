#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,q,x,y,a,b;
vector<int>*adj;
bool *called;
map<pair<int,int>,bool>visited;

void bfs(){
    queue<int>q;
    for(auto i:adj[0]) {
        q.push(i);
        visited[{0,i}]=1;
        called[i]=1;
    }
    int now; 
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(auto i:adj[now]){
            if(!called[i]){
                called[i]=1;
                visited[{min(i,now),max(i,now)}]=1;
                q.push(i);
            }
        } 
    }
}


int main(){
    int t,T=1;cin>>t;
    while(t--){
        cin>>n>>m;
        bool vis[n+1]{};
        called=vis;
        vector<int>arr[n+1];
        adj=arr;
        pair<int,int>edges[m];
        for(int i=0;i<m;++i){
            cin>>x>>y;
            edges[i].first=x,edges[i].second=y;
        }
        sort(edges,edges+m);
        
        for(int i=0;i<m;++i){
            x=edges[i].first,y=edges[i].second;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        bfs();
        cin>>q;
        cout<<"Case "<<T++<<":\n";
        while(q--){
            cin>>a>>b;
            cout<<(visited[{min(a,b),max(a,b)}]==1?"Yes\n":"No\n");    
        }
        visited.clear();
    }
}