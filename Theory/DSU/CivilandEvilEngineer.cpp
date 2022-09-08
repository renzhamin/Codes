#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int parent[101],sz[101];

int root(int x){
    return (x==parent[x]?x:parent[x]=root(parent[x]));
}

void Union(int x,int y){
    if(sz[x]>sz[y]) swap(x,y);
    parent[x]=y;
    sz[y]+=sz[x];
}

ll kruskal(vector<pair<int,pair<int,int>>>edges){
    int n=edges.size(),x,y;
    ll s=0;
    for(int i=0;i<n;++i){
        x=root(edges[i].second.first),
        y=root(edges[i].second.second);
        if(x==y) continue;
        Union(x,y);
        s+=edges[i].first;
    }
    return s;
}
void reset(int n){
    for(int i=0;i<=n;++i){
        parent[i]=i;
        sz[i]=1;
    }
}
int main(){
    int t,T=1;cin>>t;
    while(t--){
        vector<pair<int,pair<int,int>>>edges;
        int n;cin>>n;
        int a,b,w,x,y;
        reset(n);
        while(cin>>a>>b>>w && (a+b+w)){
            auto tmp=make_pair(w,make_pair(a,b));
            edges.emplace_back(tmp);
        }
        sort(edges.begin(),edges.end());
        ll s1=kruskal(edges);
        reverse(edges.begin(),edges.end());
        reset(n);
        ll s2=kruskal(edges);

        cout<<"Case "<<T++<<": ";
        if((s1+s2)&1)
            cout<<s1+s2<<"/"<<2<<"\n";
        else
            cout<<(s1+s2)/2<<"\n";
    }
}
