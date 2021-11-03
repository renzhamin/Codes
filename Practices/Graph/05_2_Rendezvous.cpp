#include <bits/stdc++.h>
#include <string>
#define ll long long 
using namespace std;

#define reset for(int i=0;i<mx;i++)for(int j=0;j<mx;j++)d[i][j]=INT_MAX;
#define mx 23

ll u,v,d[mx][mx],n,m,tmp,w,ans,sum;

void floydWarshall(){
    for(int k=0;k<mx;k++){
        for(int j=0;j<mx;j++){
            for(int i=0;i<mx;i++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            } 
        }
    }
}

int main(){
    string name;
    int T=1;
    while(cin>>n>>m && (n+m)){
        reset
        string mp[n+1];
        for(int i=1;i<=n;++i){
            cin>>mp[i];
        }
        while(m--){
            cin>>u>>v>>w;
            d[u][v]=w,d[v][u]=w;
        }
        floydWarshall();
        sum=LLONG_MAX; tmp=0;
        for(int i=1;i<=n;i++,tmp=0){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                tmp+=d[j][i];
            }
            if(tmp<sum){
                sum=tmp; ans=i;
            } 
        }
        cout<<"Case #"<<T++<<" : ";
        cout<<mp[ans]<<"\n";
    }
}
