#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define N 100001

ll dp[N][3],a[N][3];

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];

    for(int i=0;i<3;i++) dp[0][i]=a[0][i];

    for(int i=1;i<n;++i){
        dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]); 
        dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=a[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<"\n";
}
