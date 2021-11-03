#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll lqa(ll *arr,int n,ll value){
    ll i=lower_bound(arr,arr+n,value)-arr;
    if(i==0 && arr[i]>value) return -1;
    if(i==n) i--;
    if(arr[i]>value && i) i--;
    return i;
}

ll nc2(ll n){
    if(n<2) return 0;
    return n/2.0*(n-1);
}

int main(){
    ll n,d; 
    cin>>n>>d;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll ind,ans=0;
    for(int i=0;i<n-2;i++){
        ind=lqa(arr,n,arr[i]+d);
        if(ind-i<2) continue;
        ans+=nc2(ind-i);
    } 
    cout<<ans<<"\n";
}