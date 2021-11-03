#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,k;

ll before(ll x){
    ll s=0,tmp=1;
    for(ll i=1;i<=n && tmp>0;++i){
        tmp = min(x/i,m);
        s+=tmp;
    }
    return s;
}

ll bs(){
    ll lo=1,hi=n*m,mid,ans=1;
    while(lo<=hi){
        mid=(lo+hi)>>1LL;
        if(before(mid-1)<k)
            lo=mid+1,ans=mid;
        else
            hi=mid-1;
    }
    return ans;
}

int main(){
    cin>>n>>m>>k;
    cout<<bs()<<"\n";
}