#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<int>nums={1,5,5,11};
const int mx=2e4+1;
int dp[201][mx],n,sum;
void cor();

int main(){
    sum=accumulate(nums.begin(),nums.end(),0)/2;
    n=nums.size();
    dp[0][sum]=dp[1][sum]=1;

    for(int i=n-1;i>=0;i--){
        for(int w=0;w<sum;w++){
            dp[i&1][w]=dp[(i+1)&1][w] | dp[(i+1)&1][w+nums[i]];
        }
    }
    cout<<dp[0][0]<<"\n";
}

void cor(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++,cout<<endl){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j] | \
                       (j>=nums[i-1] && dp[i-1][j-nums[i-1]]);
            cout<<dp[i][j]<<" ";
        }
    }
}


// int f(int i,int w){
//     if(i==n || w>sum)
//         return 0;
//     if(w==sum)
//         return 1;
//     if(dp[i][w]!=-1)
//         return dp[w];
//     return dp[i][w] = f(i+1,w) | f(i+1,w+nums[i]);
// }

