#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i+1];
    ll xr=0;
    for(int i=0;i<n;i++) xr^=i;
    ll Q=0;
    for(int i=1;i<=n-2;i++) Q^=arr[i];
    ll s=arr[n-1]^xr;
    cout<<s<<"\n";
    Q^=arr[n-1]^xr;
    Q^=arr[n]^xr;
    cout<<Q<<"\n"; 
}