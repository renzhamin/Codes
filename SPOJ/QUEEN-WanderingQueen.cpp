#include <bits/stdc++.h>
#define ll long long 
using namespace std;


struct cell{
    ll i,j;
};

string s[1001];
ll n,m,d[1001][1001];

int di[8]={0,1,1, 1,-1,-1,-1, 0},
    dj[8]={1,1,0,-1, 1, 0,-1,-1};

#define inbound(a) (a.i<n && a.i>=0 && a.j<m && a.j>=0 && s[a.i][a.j]!='X')


void bfs(cell start){
    memset(d,0,sizeof(d));
    queue<cell>q;
    q.push(start);
    while(!q.empty()){
        cell source=q.front();
        q.pop();
        for(int i=0;i<8;++i){
            cell path=source;
            path.i+=di[i],path.j+=dj[i];
            while(inbound(path)){
                ll &cur_d=d[path.i][path.j];
                if(!cur_d){
                    cur_d=d[source.i][source.j]+1;
                    q.push(path);
                }
                if(cur_d-1!=d[source.i][source.j]) break;
                path.i+=di[i],path.j+=dj[i];
            }
        }
    }
}


int main(){
    int t;cin>>t;
    size_t f;
    cell start,finish;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>s[i];
            f=s[i].find('S');
            if(f!=string::npos) 
                start.i=i,start.j=f;
            f=s[i].find('F');
            if(f!=string::npos) {
                finish.i=i,finish.j=f;
            }
        }
        bfs(start);
        ll &ans=d[finish.i][finish.j];
        if(!ans) ans--;
        cout<<ans<<"\n";        
    }
}