#include <bits/stdc++.h>
#define ll long long 
#define inbound(x,y) x==n || x<0 || y==m || y<0 || s[x][y]=='.' || vis[ci][cj]
#define t tv[blacks[i].first][blacks[i].second]

using namespace std;

ll n,m,k,checked,ans,l;
char s[8][8];
pair<int,int>blacks[8];
vector<pair<int,int>>now;
bool vis[8][8];
bool r[8],c[8],tv[8][8];


bool vis2[8][8];

bool check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#'){
                if(vis[i][j]) continue;
                if((r[i] & c[j])) 
                    return 0;
            }
        }
    }
    return 1;
}

void nck(int i,int items){
    if(items==k){
        if(check()) {
            ans++;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]){
                        cout<<i+1<<" "<<j+1<<"\n";
                    }
                }
            }
            cout<<"g"<<"\n";
        }
        return;
    }
    if(i==l) return;
    // if(l-i-1+items>=k)
    int &ci=blacks[i].first,&cj=blacks[i].second;
    r[ci]=1,c[cj]=1,vis[ci][cj]=1;
    nck(i+1,items+1);
    r[ci]=0,c[cj]=0,vis[ci][cj]=0;
    nck(i+1,items);
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>s[i][j];
            if(s[i][j]=='#'){
                blacks[l].first=i;
                blacks[l++].second=j;
            }
        }
    }
    nck(0,0);
    cout<<ans<<"\n";
}