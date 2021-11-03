#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    ll arr[n],x;
    map<ll,ll>a,b,v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        a[arr[i]]++;
    }
    for(int i=0;i<m;i++) {
        cin>>x; b[x]++;
    }

    ll ans=0;

    for(int i=0;i<n;i++){
        if(!v[arr[i]]){
            v[arr[i]]=1;
            ans+=a[arr[i]]*b[arr[i]];
        }
    } 

    cout<<ans<<"\n";


}
