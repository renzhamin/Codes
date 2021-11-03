#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int M=1e9+7;
vector<int>g[20];
int n,m,a,b,N;
int dp[20][1<<20];

int main(){
    cin>>n>>m; N=1<<n;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a-1].emplace_back(b-1);
    }
    dp[0][1]=1;

    for(int mask=1;mask<N-2;mask+=2){
        for(int i=0;i<n-1;i++){
            if(!(mask>>i&1)) continue;
            for(auto j:g[i]){
                if((mask>>j)&1) continue;
                int &next=dp[j][mask|1<<j];
                next = (next+dp[i][mask])%M;
            }
        }
    }

    cout<<dp[n-1][N-1]<<"\n";

}


int f(int i,int mask){
    if(mask==N-1)
        return 1;
    if(dp[i][mask]!=-1)
        return dp[i][mask];
    if(i==n-1)
        return 0;

    int ways=0;
    for(auto j:g[i]){
        if(!((mask>>j)&1))
            ways+=f(j,mask|(1<<j)),ways%=M;
    }
    return dp[i][mask] = ways%M;
}



