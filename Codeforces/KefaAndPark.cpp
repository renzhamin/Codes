#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<int>*adj;
bool *visited,*flag;
ll n,m,x,y,ans;

void dfs(int v,int cur=0){
    visited[v]=1;
    
    if(!flag[v]) cur=0;
    else {
        cur++;
        if(cur>m) return;
    }

    bool leaf=1;
    
    for(auto j:adj[v]){
        if(!visited[j]){
            leaf=0;
            dfs(j,cur);
        }
    }
    if(leaf && cur<=m) ans++;
}

int main(){
    cin>>n>>m;
    vector<int>arr[n+1];
    bool v[n+1]{},f[n+1]{};
    for(int i=0;i<n;i++) cin>>f[i+1];
    visited=v; flag=f;
    adj=arr;

    for(int i=0;i<n-1;++i){
        cin>>x>>y;
        arr[x].emplace_back(y);
        arr[y].emplace_back(x);
    }

    dfs(1);
    cout<<ans<<"\n";
}