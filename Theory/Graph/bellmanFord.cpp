// uva 11280
// finding shortest path with maximum edge limit
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define inf INT_MAX
#define relax(x) for(int i=0;i<m;i++){if(d[E[i].u]==inf) continue;\
    tmp = d[E[i].u]+E[i].w; if(tmp<kd[E[i].v]){x} }

const int Nmx=101;
const int Emx=Nmx*Nmx;

struct edge{
    ll u,v,w;
}E[Emx];

ll d[Nmx],kd[Nmx],ck[Nmx],n,m,u,v,w,q,tmp;

void bellmanFord(int source){
    for(int i=0;i<=n;i++) d[i]=inf;
    d[source]=0;

    for(int j=0;j<n-1;j++){
        copy(d,d+n,kd);
        relax( kd[E[i].v] = tmp; )
        copy(kd,kd+n,d);
        ck[j]=d[n-1];
    }
}

unordered_map<string,int>mp;
string us,vs;

int main(){
    int t,T=1;cin>>t;
    while(t--){
        if(T!=1) cout<<"\n";
        cout<<"Scenario #"<<T++<<"\n";
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>us; mp[us]=i;
        } 
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>us>>vs>>w;
            E[i]={mp[us],mp[vs],w};
        } 
        bellmanFord(0);
        cin>>q;
        while(q--){
            cin>>v;
            if(v>n-2) v=n-2;
            ll &c=ck[v];
            if(c==inf)
                cout<<"No satisfactory flights"<<"\n";
            else
                cout<<"Total cost of flight(s) is $"<<c<<"\n";
            
        }
        mp.clear();
    }
}

