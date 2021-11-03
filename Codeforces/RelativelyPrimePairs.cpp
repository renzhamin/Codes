#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll l,r;cin>>l>>r;
    ll i=l;
    cout<<"YES"<<"\n";
    while(i<r){
        cout<<i++<<" "<<i++<<"\n";
    }
}