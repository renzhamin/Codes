#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll sum,limit;
    cin>>sum>>limit;
    vector<ll>ans;
    ll s=0,ip=limit,tmp;
    while(ip>0){
        tmp=ip;
        ip--;
        ll i=0;
        while(tmp%2==0)tmp/=2,i++;
        tmp=1LL<<i;
        if(s+tmp>sum) continue;
        s+=tmp;
        ans.emplace_back(ip+1);
    }
    if(s!=sum) done(-1)
    cout<<ans.size()<<"\n";
    for(auto i:ans)cout<<i<<" "; 

}