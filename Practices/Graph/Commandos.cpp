#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int start,dest,ds[101],de[101];
vector<int>*adj;
bool vis[101];

void bfs(){
    memset(ds,0,sizeof(ds));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(start); vis[start]=1;
    int pre;
    while(!q.empty()){
        pre=q.front();
        q.pop();
        for(int j:adj[pre]){
            if(vis[j]) continue;
            vis[j]=1;
            q.push(j);
            ds[j]=ds[pre]+1;
        }
    }
}

int ret(){
    memset(vis,0,sizeof(vis));
    memset(de,0,sizeof(de));
    queue<int>q;
    q.push(dest); vis[dest]=1;
    int pre,ans=-1;
    while(!q.empty()){
        pre=q.front();
        q.pop();
        for(int j:adj[pre]){
            if(vis[j]) continue;
            vis[j]=1;
            q.push(j);
            de[j]=de[pre]+1;
            ans=max(ans,de[j]+ds[j]);
        }
    }
    return max(0,ans);
}

int main(){
    int t,T=1;cin>>t;
    int n,r,u,v;
    while(t--){
        cin>>n>>r;
        vector<int>arr[n];
        while(r--){
            cin>>u>>v;
            arr[u].emplace_back(v);
            arr[v].emplace_back(u);
        }
        cin>>start>>dest;
        adj=arr;
        bfs();
        cout<<"Case "<<T++<<": ";
        int ans=ret();
        cout<<ans<<"\n";
    }
}
