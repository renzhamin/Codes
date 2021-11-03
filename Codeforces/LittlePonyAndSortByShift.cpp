#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll arr[n],p=0,mn=1e8,mi=-10;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n && p<2;++i){
        if(arr[i]>arr[(i+1)%n]){
            p++;
            mi=i;
        }
        if(p>1) done(-1)
    }
    if(!p) mi=n-1;
    cout<<n-mi-1<<"\n";
}