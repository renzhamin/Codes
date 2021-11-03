#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll fact_iter(ll n){
    ll ans = 1;
    for(ll i=2;i<=n;i++)
        ans *= i;
    return ans;
}

ll fact_rec(ll n){
    return (n<=1? 1:n*fact_rec(n-1));
}


int main(){
    ll n; cin>>n;
    cout<<fact_iter(n)<<" (using iteration)"<<"\n";
    cout<<fact_rec(n)<<" (using recursion)"<<"\n";
}
