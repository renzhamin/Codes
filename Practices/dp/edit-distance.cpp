#include <bits/stdc++.h>
#include <cstring>
#define ll long long 
using namespace std;
const int mx=501;
string s="horse",w="ros";
int dp[mx][mx],n=s.size(),m=w.size(),top[mx][mx],cur;
// string s="intention",w="execution";
void bot();int solve(int,int);

void rec(){
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<"\n";
}

int main(){
//     rec();
//     for(int i=0;i<=n;i++,cout<<endl){
//         for(int j=0;j<=m;j++){
//             cout<<top[i][j]<<"\t";
//         }
//     }
    bot();
    cout<<"------------"<<"\n";
    for(int i=0;i<=n;i++,cout<<endl){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<"\t";
        }
    }

}


int solve(int i,int j){
    if(j==m){
        top[i][j]=++cur;
        return dp[i][j]=n-i;
    }
    if(i==n){
        top[i][j]=++cur;
        return dp[i][j]=m-j;
    }
    if(dp[i][j]!=-1){
        top[i][j]=++cur;
        return dp[i][j];
    }

    if(s[i]==w[j]){
        dp[i][j]=solve(i+1,j+1);
        top[i][j]=++cur;
        return dp[i][j];
    }

    int a,b,c; a=b=c=INT_MAX;

    a=solve(i+1,j+1);
    b=solve(i,j+1);
    c=solve(i+1,j);
    top[i][j]=++cur;
    return dp[i][j] = 1+min({a,b,c});
}

void bot(){
    memset(dp,0,sizeof(dp));
    n = s.length();
    m = w.length();
    for(int i=0;i<n;i++)
        dp[i][m] = n-i;
    for(int j=0;j<m;j++)
        dp[n][j] = m-j;
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(s[i]==w[j])
                dp[i][j] = dp[i+1][j+1];
            else
                dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
        }
    }
}
