#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define nfor for(int i=0;i<mx;i++)for(int j=0;j<mx;j++)
#define reset nfor d[i][j]=INT_MAX;
#define reset_path nfor\
    path[i][j]=(d[i][j]>=INT_MAX?-1:i);
#define mx 101

ll u,v,tmp,d[mx][mx],path[mx][mx];

void floydWarshall(){
    for(int k=0;k<mx;k++){
        for(int j=0;j<mx;j++){
            for(int i=0;i<mx;i++){
                tmp = d[i][k]+d[i][j];

            } 
        }
    }
}

void getAvg(){
    double sum=0,edge=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(d[i][j]>=INT_MAX || i==j)
                continue;
            sum+=d[i][j];
            edge++;
        }
    }
    sum/=edge;
    cout<<setprecision(3)<<fixed<<sum<<" clicks\n";
}

void printPath(int u,int v){
    vector<int>p;
    p.emplace_back(v);
    while(u!=v){
        v=path[u][v];
        p.emplace_back(v);
    }
    for(int i=p.size()-1;i>=0;i--){
        cout<<p[i]+1<<" -> ";
    }
    cout<<"\n";
}


int main(){
    int T=1;
    reset;
    while(cin>>u>>v){
        if(!(u+v)){
            if(!tmp) break;
            floydWarshall();
            cout<<"Case "<<T++<<": average length between pages = ";
            getAvg();
            reset;
        }
        d[u][v]=1;
        tmp=u+v;
    }
}
