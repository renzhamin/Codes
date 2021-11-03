#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
    ll n,m,x,y;
    cin>>n>>m;
    ll arr[n],cs[n+1]{};
    for(int i=0;i<n;i++) cin>>arr[i];
    while(m--){
        cin>>x>>y;
        cs[x-1]++;
        cs[y]--;
    }
    for(int i=1;i<n;i++) cs[i]+=cs[i-1]; 
    ll ans=0;
    sort(arr,arr+n);
    sort(cs,cs+n);
    for(int i=0;i<n;i++){
        ans+=arr[i]*cs[i];
    } 
    cout<<ans<<"\n";
}