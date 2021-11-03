#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<int>*adj;
int n,m;
bool f=1;

void dfs(int p,bool *vis,bool *working){
    if(working[p]) {f=0;return;}
    if(vis[p]) return;
    vis[p]=working[p]=1;
    for(int i:adj[p]){
        dfs(i,vis,working);
    }
    working[p]=0;
}


int main(){
    int t,T=1;cin>>t;
    string a,b;
    while(t--){
        vector<pair<int,int>>pr;
        map<string,int>mp;
        f=1;
        cin>>m;
        while(m--){
            cin>>a>>b;
            if(!mp[a]) mp[a]=++n;
            if(!mp[b]) mp[b]=++n;
            pr.emplace_back(mp[a],mp[b]);
        }
        vector<int>arr[n+1];
        bool vis[n+1]{},working[n+1]{};
        for(int i=0;i<pr.size();i++) 
            arr[pr[i].second].emplace_back(pr[i].first);
        adj=arr;
        for(int i=1;i<=n;++i){
            dfs(i,vis,working);
        }
        cout<<"Case "<<T++<<": ";
        cout<<(f?"Yes\n":"No\n");	
    }
}
