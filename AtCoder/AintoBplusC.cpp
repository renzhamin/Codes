#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,ans;
    cin>>n;
    ans=n-1;
    for(int i=2;i<n;++i){
        ans+=n/i;
        if(n%i==0) ans--;
    }
    cout<<ans<<"\n";
}