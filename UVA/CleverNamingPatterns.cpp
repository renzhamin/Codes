#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
const int mx=90;
ll n,k,m,res[mx][mx],minflow,u,v,w,maxflow;
vector<int>g[mx];
int s=88,e=89;
bool vis[mx];

bool flow(int u){
    if(u==e) return 1;
    vis[u]=1;
    for(auto v:g[u]){
        if(vis[v] || !res[u][v]) continue;
        bool f=flow(v);
        if(!f) continue;
        res[u][v]--,res[v][u]++;
        return 1;
    }
    return 0;
}
string vs[31][26],str;

int main(){
    int t,T=1;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            g[s].emplace_back(i),res[s][i]=1;

        for(int i=0;i<n;i++){
            u=i+26,v=e;
            g[u].emplace_back(e);
            res[u][e]=1;

            cin>>k;
            for(int j=0;j<k;j++){
                cin>>str;
                for(auto &i:str) i=tolower(i);
                str[0]=toupper(str[0]);
                int c=str[0]-'A';
                vs[i][c] = str;
                g[c].emplace_back(u);
                g[u].emplace_back(c);
                res[c][u]=1;
            }
        } 

        while( memset(vis,0,sizeof(vis)) && flow(s) );

        cout<<"Case #"<<T++<<":\n";

        for(int i=0;i<n;i++){
            for(auto j:g[i]){
                if(!res[i][j]){
                    cout<<vs[j-26][i]<<"\n";
                    break;
                }
            }
        } 
        memset(res,0,sizeof(res));
        for(auto &i:g) i.clear(); 
    }
}

/*

4
3
2 Apples Oranges
1 Bananas
5 Apricots Blueberries Cranberries Zuccini Yams
1
1 ApPlEs
2
2 a b
1 axe
4
4 Aa Ba Ca Da
3 Ab Bb Cb
2 Ac Bc
1 Ad

*/
