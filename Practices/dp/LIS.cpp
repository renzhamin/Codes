#include <bits/stdc++.h>
#define ll long long 
#define done(r) {x;return r;} 
using namespace std;
const int mx=250;
int dp[mx],n;

vector<int>nums={1,3,6,7,9,4,10,5,6};

int main(){
    memset(dp,0,sizeof(dp));
    int n=nums.size();
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]);
        }
        dp[i]++;
        ans=max(ans,dp[i]);
    }
}



int solve(int i){
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=0;
    for(int k=i-1;k>=0;k--){
        if(nums[i]>nums[k]){
            ans=max(ans,solve(k));
        }
    }
    return dp[i]=1+ans;
}

