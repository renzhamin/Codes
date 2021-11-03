#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n,m,cmax;
bool flag[101][101];

vector<int>have,ans;

void sub(int now){
    if(now>n){
        if(have.size()>cmax){
            cmax=have.size();
            ans=have;
        } 
        return;
    }
    
    sub(now+1);
    
    for(auto i:have)
        if(flag[i][now]) return;

    have.emplace_back(now);
    sub(now+1);
    have.pop_back();
}

int main(){
    int t;cin>>t;
    while(t--){
        cmax=0;
        memset(flag,0,sizeof(flag));
        cin>>n>>m;
        ll x,y;
        while(m--){
            cin>>x>>y;
            flag[x][y]=1;
            flag[y][x]=1;
        }
        sub(1);
        cout<<cmax<<"\n";
        for(int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans[ans.size()-1]<<"\n"; 
    }
}