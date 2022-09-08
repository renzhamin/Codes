#include <bits/stdc++.h>
#define ll long long 
#define mx 200000
using namespace std;
ll a[mx],dp[mx];

int main(){
    int n;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0]=0,dp[1]=abs(a[1]-a[0]);

    for(int i=2;i<n;++i){
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n-1]<<"\n";
}
