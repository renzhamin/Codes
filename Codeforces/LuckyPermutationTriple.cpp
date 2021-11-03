#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    if(!(n&1)) cout<<-1<<"\n";
    else {
        ll a[n],b[n];
        iota(a,a+n,0);
        b[n-1]=0;
        iota(b,b+n-1,1);
        for(auto i:a)cout<<i<<" ";
        cout<<"\n";
        for(auto i:b)cout<<i<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++)
            cout<<(a[i]+b[i])%n<<" ";  
    }
}