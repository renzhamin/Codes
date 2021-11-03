#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
ll a[(int)2e5+10],b[(int)2e5+10],d,ap,bp,af,bf;

ll dif(ll d){
    int ind=upper_bound(a,a+n,d)-a;
    ap=ind*2+(n-ind)*3;
    ind=upper_bound(b,b+m,d)-b;
    bp=ind*2+(m-ind)*3;
    return ap-bp;
}

#define updatecur     \
    if(cur>ans){       \
        af=ap,bf=bp;    \
        ans = cur;       \
    }

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b,b+m);
    
    ll cur = max(0LL,a[0]-1);
    ll ans = dif(cur);
    af=ap,bf=bp;
    
    for(int i=0;i<n;++i){
        cur = dif(a[i]);
        updatecur
    }
    cur = dif(a[n-1]+1);
    updatecur

    for(int i=0;i<m;++i){
        cur = dif(b[i]);
        updatecur   
    }
    cur = dif(b[n-1]+1);
    updatecur

    cout<<af<<":"<<bf<<"\n";

}
