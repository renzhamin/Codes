#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    map<ll,ll>x,y;
    map<pair<ll,ll>,ll>h;
    ll x1,y1,n,ans=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x1>>y1;
        ans+=x[x1]+y[y1];
        if(h[{x1,y1}])ans-=h[{x1,y1}];
        h[{x1,y1}]++;
        x[x1]++;y[y1]++;
    }
    cout<<ans<<"\n";

}