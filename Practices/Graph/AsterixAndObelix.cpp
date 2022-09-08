#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define nfor for(int i=0;i<mx;i++)for(int j=0;j<mx;j++)
#define reset nfor d[i][j]=INT_MAX;
#define mx 101
#define fs max({feast[i][k],feast[k][j]})
 
ll u,v,tmp,d[mx][mx],feast[mx][mx];

void floydWarshall(int N){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                tmp = d[i][k]+d[k][j]+fs;
                if(tmp < d[i][j]+feast[i][j]){
                    d[i][j] = tmp-fs;
                    feast[i][j]=fs;
                }
            } 
        }
    }
}

int n,m,q,fc[mx],w,T=1;

int main(){
    while(cin>>n>>m>>q && (n+m+q)){
        if(T!=1) cout<<"\n";
        for(int i=1;i<=n;i++){
            cin>>fc[i];
            feast[i][i]=fc[i];
        } 
        reset
        while(m--){
            cin>>u>>v>>w;
            d[u][v]=d[v][u]=w;
            feast[u][v]=feast[v][u]=max(fc[u],fc[v]);
        }
        for(int i=0;i<3;i++){
            floydWarshall(n);
        } 
        cout<<"Case #"<<T++<<"\n";
        while(q--){
            cin>>u>>v;
            cout<<(d[u][v]>=INT_MAX?-1:d[u][v]+feast[u][v])<<"\n";
        }
    }
}
