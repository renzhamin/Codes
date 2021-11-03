#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll c,a,b;
    cin>>c;
    if(c<3) done(-1);
    ll x=4;
    if(c&1) x=2;
    a=c*c/x,b=a+1;
    if(!(c*c%4)) a--;
    cout<<a<<" "<<b<<"\n";
}