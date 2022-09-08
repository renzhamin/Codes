#include <bits/stdc++.h>
#define ll long long
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

ll GCD, x, y, tmp;
void extendedEuclid(ll A, ll B) {
    if(B == 0) 
        GCD = A,x = 1,y = 0;
    else {
        extendedEuclid(B, A%B);
        tie(x,y)=make_tuple(y,x-A/B*y);
    }
}



int main( ) {
    ll a,b;
    while(cin>>a>>b){
        extendedEuclid(a,b);
    }
}
