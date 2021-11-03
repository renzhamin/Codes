#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll M=(int)1e9+7;
    ll n;cin>>n;
    ll arr[n+1],cs[n+1]{};
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        cs[i]=cs[i-1]+arr[i];
    }
    ll ans=0;
    __int128 tmp;
    for(int i=1;i<n;++i){
        tmp=cs[n]-cs[i];
        ans=((ans+arr[i]*tmp)%M)%M;
    }
    cout<<ans<<"\n";
}