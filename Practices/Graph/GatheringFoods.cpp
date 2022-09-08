#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n,tl,dist[12][12];
string s[15];
bool visited[12][12];
pair<int,int>mp[30];
int dx[]={0,0,-1,1},
    dy[]={1,-1,0,0};
int bfs(int si,int sj,char x){
    bool visited[12][12]{};
    queue<pair<int,int>>q;
    q.push({si,sj});
    visited[si][sj]=1;
    
    int pi,ci,pj,cj,dist[12][12]{};
    
    while(!q.empty()){
        pi=q.front().first,pj=q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            ci=pi+dx[i],cj=pj+dy[i];
            if(ci==n || cj==n || ci<0 || cj<0 || visited[ci][cj] || s[ci][cj]=='#') 
                continue;
            if(s[ci][cj]!='.' && s[ci][cj]>x) 
                continue;

            if(s[ci][cj]==x) 
                return dist[pi][pj]+1;

            dist[ci][cj]=dist[pi][pj]+1;
            visited[ci][cj]=1;
            q.push({ci,cj});            
        }
    }
    return -1;
}

int main(){
    
    int t,T=1;cin>>t;
    while(t--){
        tl=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<n;j++) 
                if(s[i][j]!='.' && s[i][j]!='#')
                    mp[s[i][j]-'A']={i,j},tl++;
        }
        int ans=0,tmp=0;
        cout<<"Case "<<T++<<": ";
        for(int i=0,x='A';i<tl-1;i++,x++){
            tmp=bfs(mp[x-'A'].first,mp[x-'A'].second,x+1);
            if(tmp==-1) break;
            ans+=tmp;
        }
        (tmp==-1)?cout<<"Impossible"<<"\n":cout<<ans<<"\n";
    }

}