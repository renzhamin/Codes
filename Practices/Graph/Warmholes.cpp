//bellmanFord 
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define relax(x) for(int i=0;i<m;i++){\
    tmp = d[E[i].u]+E[i].w; if(tmp<d[E[i].v]){x} }

const int Emx=2e3+1;
const int Nmx=1e3+1;

struct edge{
    ll u,v,w;
}E[Emx];

ll d[Nmx],n,m,u,v,w,tmp;
bool negCycle;

void bellmanFord(int source,bool checkCycle=0){
    for(int i=0;i<n;i++) d[i]=INT_MAX;
    d[source]=0;

    for(int j=0;j<n-1;j++){
        relax( d[E[i].v] = tmp; )
    }

    if(!checkCycle) return;

    negCycle=0;
    relax( negCycle=1; break; )
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>E[i].u>>E[i].v>>E[i].w;
        }
        bellmanFord(0,1);
        cout<<(negCycle?"possible\n":"not possible\n");	
    }
}
