#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,k,d,M=1000000007,mem[101][2];

ll dfs(ll sum,bool yes){
    if(sum>n) return 0;
    if(sum==n){
        return yes;
    }

    ll &now = mem[sum][yes];
    if(now!=-1) return now;

    ll ans=0;
    for(int i=1;i<=k;++i){
        if(i>=d) yes=1;
        ans+=dfs(sum+i,yes);
        ans%=M;
    }
    return now=ans;
}

int main(){
    memset(mem,-1,sizeof(mem));
    cin>>n>>k>>d;
    ll ans=dfs(0,0);
    if(ans==-1) ans=0;
    cout<<ans<<"\n";
}