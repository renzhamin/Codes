#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

const ll M=2000000011;
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
    ll n;
    int t,T=1;cin>>t;
    while(t--){
        cin>>n;
        cout<<"Case #"<<T++<<": ";
        if(n==1) done(1)
        done(BigMod(n,n-2));
    }
}