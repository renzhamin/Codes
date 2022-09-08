#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define N 101

ll dp[N][100001];
pair<int,int>item[N];

int main(){
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>item[i+1].first>>item[i+1].second;
    } 

    for(int i=0;i<=n;i++){
       dp[i][0]=dp[0][i]=0;
    } 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j]=(j<item[i].first?dp[i-1][j]:max(dp[i-1][j],item[i].second+dp[i-1][j-item[i].first] ));
        }
    }
    cout<<dp[n][w]<<"\n";

}
