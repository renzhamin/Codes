#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,a[3],M=(ll)1e9+7;
    cin>>a[1]>>a[2]>>n;
    a[0]=a[2]-a[1];
    ll ans = a[n%3];
    ll m=ceil(n/3.0);
    if(!(m&1) && n>3) ans=-ans;
    ans = (ans+2*M)%M;
    cout<<ans<<"\n";
}