//Matrix_Chain_Multiplication
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=101;
int n,arr[mx],dp[mx][mx],cs[mx];
#define merge(i,j,k) ((cs[k]-cs[i-1])%100)*((cs[j]-cs[k])%100)

int f(int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int l=f(i,k);
        int r=f(k+1,j);
        ans=min(ans,l+r+merge(i,j,k));
    }
    return dp[i][j]=ans;
}

int main(){
    while(cin>>n){
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            cs[i]=cs[i-1]+arr[i];
        } 
        cout<<f(1,n)<<"\n";
    }
}

