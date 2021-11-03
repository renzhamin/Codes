#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,d;
    cin>>n>>d;
    pair<ll,ll>arr[n];
    ll sum[n];
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);

    sum[0]=arr[0].second;
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+arr[i].second;

    ll x,r,ans=arr[0].second;
    for(int i=0;i<n;++i){
        r=arr[i].first+d;
        x=lower_bound(arr+i,arr+n,make_pair(r,(ll)INT_MIN))-arr-1;
        if(i==0)ans=max(ans,sum[x]);
        else ans=max(ans,sum[x]-sum[i-1]);
    } 
    cout<<ans<<"\n";
}