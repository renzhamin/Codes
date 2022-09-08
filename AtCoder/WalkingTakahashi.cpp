#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    ll m=x/d;
    if(m>=k) done(x-k*d)
    k-=m;
    m=x%d;
    if(k&1) done(abs(m-d))
    done(m)
}