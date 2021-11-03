#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int di[]={0,0,-1,1},
    dj[]={1,-1,0,0};
int n,m,k;
string s[501];
bool v[501][501];

void dfs(int ci,int cj){
    if(ci==n || ci<0 || cj==m || cj<0 || v[ci][cj] || s[ci][cj]=='#')
        return;
    v[ci][cj]=1;
    for(int i=0;i<4;++i){
        dfs(ci+di[i],cj+dj[i]);
    }
    if(k>0)s[ci][cj]='X',k--;
}


int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j] && s[i][j]!='#')
                dfs(i,j);
        }
    }
    for(int i=0;i<n;i++)cout<<s[i]<<"\n";     
}
