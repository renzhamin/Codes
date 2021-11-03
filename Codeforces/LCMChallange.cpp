#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll n; cin>>n;
    if(n<3) done(n)
    ll a,b;
    if(!(n&1)&&n-3>0){
        if(n%3) 
            done(n*(n-1)*(n-3))
        done((n-1)*(n-2)*(n-3))
    }
    done(n*(n-1)*(n-2))
}