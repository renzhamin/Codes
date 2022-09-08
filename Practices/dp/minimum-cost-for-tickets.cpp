//LeetCode
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=366;
vector<int>day={1,5,8,9,10,12,13,16,17,18,19,20,23,24,29};
vector<int>cost={3,12,54};
int n=day.size(),dp[mx];
int solve(int);
#define next(t) upper_bound(day.begin()+i,day.end(),t)-day.begin()
#define ind(x) dp[max(0,x)]


int main(){
    memset(dp,-1,sizeof(dp));
    cout<<solve(0)<<"\n";
}

int solve(int i){
    if(i==n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int a,b,c;
    a=cost[0]+solve(i+1);
    b=cost[1]+solve(next(day[i]+6));
    c=cost[2]+solve(next(day[i]+29));
    return dp[i]=min({a,b,c});
}

// 
// void bot(){
//     for(int i=1;i<=29;i++){
//         if(day.find(i)==day.end()) dp[i]=dp[i-1]; 
//         else
//             dp[i]=min({ind(i-1)+cost[0],ind(i-7)+cost[1],ind(i-30)+cost[2]});
//     }
//     cout<<dp[29]<<"\n";
// }

