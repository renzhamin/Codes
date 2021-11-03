#include <bits/stdc++.h>
#define ll long long 
#define valid(x,y) x>=0 && x<n && y>=0 && y<m && \
                !vis[x][y] && grid[x][y]==startcolor
using namespace std;

int dx[]={0,1,-1,0},
    dy[]={1,0,0,-1};

int n,m,sr,sc,nc,grid[1001][1001],startcolor,ci,cj;
bool vis[1001][1001];


void flood(int pi,int pj){
    vis[pi][pj]=1;
    grid[pi][pj]=nc;
    for(int i=0;i<4;++i){
        ci=pi+dx[i],cj=pj+dy[i];
        if(valid(ci,cj))
            flood(ci,cj);
    }
}

int main(){
    cin>>n>>m>>sr>>sc>>nc;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    startcolor=grid[sr][sc];
    flood(sr,sc);
    for(int i=0;i<n;i++,cout<<"\n"){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}