#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e3+1;

int dp[2][mx];

int main(){
    string text1="abcde",text2="cfaade";
    int n = text1.length();
    int m = text2.length();

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(text1[i]==text2[j])
                dp[i&1][j] = 1+dp[(i+1)&1][j+1];
            else
                dp[i&1][j] = max(dp[i&1][j+1],dp[(i+1)&1][j]);
        }
    }
    cout<<dp[0][0]<<"\n";
}
