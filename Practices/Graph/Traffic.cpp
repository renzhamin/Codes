// bellmanFord negative cycle
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define MX INT_MAX
#define relax(x) for(int i=0;i<m;i++){if(d[E[i].u]==MX) continue;\
    tmp = d[E[i].u]+E[i].w; if(tmp<d[E[i].v]){x} }

const int Emx=1e2+1;
const int Nmx=2e4+1;

struct edge{
    ll u,v,w;
}E[Emx];

ll d[Nmx],n,m,u,v,w,q,tmp;
bool negCycle;

void bellmanFord(int source,bool checkCycle=0){
    for(int i=1;i<=n;i++) d[i]=MX;
    d[source]=0;

    for(int j=1;j<n;j++){
        relax( d[E[i].v] = tmp; )
    }

    if(!checkCycle) return;

    negCycle=0;
    relax( negCycle=1; break; )
}
#define pow(x) (x)*(x)*(x)
ll bs[Nmx];

int main(){
    int T=1;
    while(cin>>n){
        for(int i=1;i<=n;i++) cin>>bs[i];
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            E[i]={u,v,pow(bs[v]-bs[u])};
        }
        bellmanFord(1,1);
        cout<<"Set #"<<T++<<"\n";
        cin>>q;
        while(q--){
            cin>>v;
            if(d[v]<3 || d[v]>=INT_MAX) cout<<"?\n";
            else cout<<d[v]<<"\n";
        }
    }
}
