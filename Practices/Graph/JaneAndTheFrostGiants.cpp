#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=201;

int n,m,df[mx][mx],d[mx][mx],l;
char s[mx][mx];
pair<int,int>fire[mx*mx],start;

int dx[]={0,0,-1,1},
    dy[]={1,-1,0,0};

int bfs(bool f=0){
    queue<pair<int,int>>q;
    bool visited[mx][mx]{};
    if(f){
        memset(df,0,sizeof(df));
        for(int i=0;i<l;i++){
            q.push(fire[i]);
            visited[fire[i].first][fire[i].second]=1; 
        }
    } else {
        memset(d,0,sizeof(d));
        if(start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1)
            return 1;
        q.push(start);
        visited[start.first][start.second]=1;
    }
    int pi,pj,ci,cj;
    while(!q.empty()){
        pi=q.front().first,pj=q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            ci=pi+dx[i],cj=pj+dy[i];
            if(ci<0 || ci>=n || cj<0 || cj>=m || visited[ci][cj] || s[ci][cj]=='#')
                continue;
            visited[ci][cj]=1;
            if(f){
                df[ci][cj]=df[pi][pj]+1;
                q.push({ci,cj});
                continue;
            } 
            if(d[pi][pj]+1<df[ci][cj]){
                d[ci][cj]=d[pi][pj]+1;
                if(ci==0 || ci==n-1 || cj==0 || cj==m-1)
                    return d[ci][cj]+1;
                q.push({ci,cj});
            }
        }
    }
    return -1;
}

int main(){
    int t,T=1,x;cin>>t;
    while(t--){
        l=0;
        cin>>n>>m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>s[i][j];
                if(s[i][j]=='J') start={i,j};
                if(s[i][j]=='F') fire[l++]={i,j};
            }
        }
        cout<<"Case "<<T++<<": ";
        bfs(1);
        x=bfs();
        (x==-1)?cout<<"IMPOSSIBLE"<<"\n":cout<<x<<"\n";
    }
}