#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,ans=0,x,l;
        map<ll,ll>a;
        cin>>n; 
        for(int i=0;i<n;i++) {
            cin>>x;
            l=log2(x);
            ans+=a[l];
            a[l]++;
        }
        cout<<ans<<"\n";
    }
}