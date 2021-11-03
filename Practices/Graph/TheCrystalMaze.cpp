#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=505;

string s[mx];
int d[mx][mx];
int n,m,q,C=0,x,y;
int dx[]={0,0,-1,1},
    dy[]={1,-1,0,0};

bool visited[mx][mx];

void dfs(int i,int j){
    if(s[i][j]=='C') C++;
    visited[i][j]=1;
    for(int k=0;k<4;++k){
        x=i+dx[k],y=j+dy[k];
        if(x==n || x<0 || y==m || y<0 || s[x][y]=='#' || visited[x][y])
            continue;
        dfs(x,y);
    }
    // cout<<i<<" "<<j<<"\n";
    d[i][j]=C;
}

 
int main(){
    int t,T=1;cin>>t;
    while(t--){
        memset(visited,0,sizeof(visited));
        cin>>n>>m>>q;
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++,C=0){
                if(!visited[i][j] && s[i][j]!='#')
                    dfs(i,j);
            }
        }
        cout<<"Case "<<T++<<":\n";
        while(q--){
            cin>>x>>y;
            cout<<d[x-1][y-1]<<"\n";
/*            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<d[i][j];
                }
                cout<<"\n";
            }
*/      }
    }
}