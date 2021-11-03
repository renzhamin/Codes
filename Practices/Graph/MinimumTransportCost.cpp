#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define nfor for(int i=0;i<mx;i++)for(int j=0;j<mx;j++)
#define reset nfor d[i][j]=INT_MAX;
#define reset_path nfor path[i][j]=j;
#define mx 101

ll u,v,tmp,d[mx][mx],tax[mx],path[mx][mx],n;

void floydWarshall(){
    for(int k=0;k<mx;k++){
        for(int j=0;j<mx;j++){
            for(int i=0;i<mx;i++){
                tmp = d[i][k]+d[k][j]+((k!=i && k!=j)?tax[k]:0);
                if(tmp<d[i][j]){
                    d[i][j]=tmp;
                    path[i][j]=path[i][k];
                }
            } 
        }
    }
}

void printPath(int u,int v){
    vector<int>p;
    p.emplace_back(u);
    while(u!=v){
        u=path[u][v];
        p.emplace_back(u);
    }
    for(int i=0;i<p.size()-1;i++){
        cout<<p[i]+1<<"-->";
    }
    cout<<p[p.size()-1]+1<<"\n";
}

int main(){
    int t,T=1;cin>>t; 
    cin.get();cin.get();
    string data;
    while(t--){
        reset
        getline(cin,data);
        stringstream s(data);
        vector<int>temp;
        while(!s.eof()){
            s>>tmp;
            temp.emplace_back(tmp);
        }
        n=temp.size();
        for(int i=0;i<n;i++){
            if(temp[i]!=-1) d[0][i]=temp[i];
        } 
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>tmp;
                if(tmp!=-1)
                    d[i][j]=tmp;
            }
        }
        for(int i=0;i<n;i++) cin>>tax[i];
        reset_path
        floydWarshall();
        cin.get();
        bool doit=0;
        while(getline(cin,data) && data.size()){
            if(doit) cout<<"\n";
            doit=1;
            stringstream ss(data);
            ss>>u; ss>>v;
            printf("From %d to %d :\nPath: ",u,v);
            u--,v--;
            printPath(u,v);
            printf("Total cost : %d\n",d[u][v]);
        }
    }
}
