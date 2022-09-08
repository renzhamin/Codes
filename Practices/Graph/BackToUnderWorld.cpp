#include <bits/stdc++.h>
#define ll long long 
#define N 100002
using namespace std;

vector<int>*adj;
bool vis[N],vamp[N];
int n,x,y,a[2];

void dfs(int u){
    vis[u]=1; 
    for(auto v:adj[u]){
        if(vis[v]) continue;
        vamp[v]=vamp[u]^1;
        a[vamp[v]]++;
        dfs(v);
    }
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        vector<int>arr[20001];
        memset(vis,0,sizeof(vis));
        memset(vamp,0,sizeof(vamp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            arr[x].emplace_back(y); 
            arr[y].emplace_back(x);
        } 
        adj=arr;
        int sum=0;
        for(int i=1;i<20001;i++){
            if(!vis[i] && !arr[i].empty()){
                dfs(i);
                sum+=max(a[0]+1,a[1]);
                a[0]=a[1]=0;
            }
        } 
        cout<<"Case "<<T++<<": ";
        cout<<sum<<"\n";
    }
}
