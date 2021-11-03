#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll val=sqrt(n)+1,s=1;
    for(ll i=2;i<=val;++i){
        if(n%i==0){
            while(n%i==0) n/=i;
            s*=i;
        }
    }
    if(n>1) s*=n;
    cout<<s<<"\n";
}