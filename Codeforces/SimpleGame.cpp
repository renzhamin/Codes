#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=m+1;
    if(m-1>=n-m) ans=m-1;
    if(n==1) ans=1;
    cout<<ans<<"\n";
}