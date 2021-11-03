#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mx=(int)1e5+1;

ll freq[mx],tmp,n,dp[mx][2];


int main(){
    ll M=-1;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        M=max(M,tmp);
        freq[tmp]++;
    }

    dp[1][1]=freq[1];

    for(int i=2;i<=M;++i){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=max(dp[i-1][1],dp[i-2][1]+freq[i]*i);    
    }

    cout<<dp[M][1]<<"\n";
}