#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,m,tmp,x,y;
    cin>>n>>m;
    ll mp[n];
    map<ll,set<ll>>color;
    for(int i=0;i<n;++i){
        cin>>tmp;
        mp[i]=tmp;
        color[tmp].emplace(tmp);
    }
    for(int i=0;i<m;++i){
        cin>>x>>y;
        x--,y--;
        color[mp[x]].emplace(mp[y]);
        color[mp[y]].emplace(mp[x]);
    }

    ll ms=0,c=1e6;

    for(auto i=color.begin();i!=color.end();++i){
        ll cl=i->first;
        ll sz=i->second.size();
        if(sz==ms && cl>c) continue;
        if(sz>=ms)
            ms=sz,c=cl;
    }
    cout<<c<<"\n";

}