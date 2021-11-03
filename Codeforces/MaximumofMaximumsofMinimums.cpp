#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull long long unsigned
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long double, long double>
#define ff first
#define ss second
#define pb push_back
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)

const int MAX=100006, MOD=1e9 + 7;

ll dp[2005][2005];
ll solve(int ind, int n, int k, int cur){

    if(cur>n) return 0;
    if(ind==k) return 1;
    if(dp[ind][cur]!=-1) return dp[ind][cur];
    ll ret=0;
    for(int i=1;cur*i<=n;i++){
        ret+=solve(ind+1,n,k,cur*i);
        ret%=MOD;
    }
    return dp[ind][cur]=ret;
}

int main(){

    int n,k;
    cin>>n>>k;
    ll ans=0;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        ans+=solve(1,n,k,i);
        ans%=MOD;
    }
    cout<<ans<<"\n";

}
