#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main(){
    ll n,r,rows;
    int t;cin>>t;
    while(t--){
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        if(min(a,b)>=m && a+b>=n+m)
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";
    }
}