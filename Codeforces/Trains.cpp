#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll a,b;
    cin>>a>>b;
    ll lcm=a*b/__gcd(a,b);
    if(abs(lcm/a-lcm/b)==1) done("Equal")
    cout<<(a>b?"Masha\n":"Dasha\n");    
}