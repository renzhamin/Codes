#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll M=1e9+7;
ll BigMod(ll base,ll power,ll mod=M){
    ll result=1;
    while(power){
        if(power&1)
            result=((__int128)result*base)%mod;
        base=((__int128)base*base)%mod;
        power>>=1LL;
    }
    return result;
}

int main(){
    int t;cin>>t;
    while(t--){
        ll n,a,b;
        cin>>a>>b>>n;
        ll x;
        if(a==b)
            x=BigMod(a,n)+BigMod(b,n);
        else
            x=BigMod(a,n,a-b)+BigMod(b,n,a-b);
        cout<<__gcd(x,a-b)<<"\n";
    }
}