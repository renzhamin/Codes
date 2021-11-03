#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll m7=n/7,m4=n/4;
    string a="-1";
    for(ll i=m7;i>=0;i--){
        m4=(n-i*7)/4;
        if(m4*4+i*7==n){
            a=string(m4,'4')+string(i,'7');
            break;
        }
    } 
    cout<<a<<"\n";
}