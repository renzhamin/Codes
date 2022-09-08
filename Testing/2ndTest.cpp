#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<ll>());
    ll ans = 0;
    for(int i=0;i<k;i++){
        ans += arr[i];
    } 
    cout<<ans<<"\n";
}
