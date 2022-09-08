//LeetCode
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=503;
int n,a[]={1,3,1,5,8,1},dp[mx][mx];

#define merge(i,j,k) a[i-1]*a[k]*a[j+1]

int f(int i,int j){
   if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;
    for(int k=i;k<=j;k++){
        int l=f(i,k-1);
        int r=f(k+1,j);
        ans=max(ans,l+r+merge(i,j,k));
    }
    return dp[i][j]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<<f(1,4)<<"\n";
}

