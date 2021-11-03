//LightOj 1026 - Critical Links
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e4+1;

vector<int>adj[mx];
int n,m,u,v,k,moment,d[mx],low[mx],parent[mx];
vector<pair<int,int>>ans;

void dfs(int u){
    d[u]=low[u]=moment++;
    for(int v:adj[u]){
        if(parent[u]==v) continue; // where it came from
        if(d[v]!=-1){ // backedge
            low[u]=min(low[u],d[v]);
        } else { // new tree edge
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<low[v])
                ans.emplace_back(min(u,v),max(u,v));
        }
    }
    adj[u].clear();
}


int main(){
    int t,T=1;cin>>t;
    while(t--){
        moment=0;
        memset(d,-1,sizeof(d));
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%d (%d)",&u,&k);
            while(k--){
                cin>>v; 
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        } 
        for(int i=0;i<=n;++i){
            if(d[i]==-1){
                dfs(i);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Case "<<T++<<":\n";
        cout<<ans.size()<<" critical links\n";
        for(auto &[u,v]:ans)
            cout<<u<<" - "<<v<<"\n";
        ans.clear();
    }
}

