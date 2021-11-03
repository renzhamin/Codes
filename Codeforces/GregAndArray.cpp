#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct opr{
    ll a,b,d;
} op[(int)2e5];

int main(){
    ll n,m,k,x,y;
    cin>>n>>m>>k;
    ll cnt[m+5]{},arr[n+5],add[n+5]{};
    for(int i=0;i<n;i++) cin>>arr[i+1];
    for(int i=1;i<=m;++i){
        cin>>op[i].a>>op[i].b>>op[i].d;
    }
    while(k--){
        cin>>x>>y;
        cnt[x]++;
        cnt[y+1]--;
    }
    for(int i=2;i<=m;++i){
        cnt[i]+=cnt[i-1];
    }
    ll tmp;
    for(int i=1;i<=m;++i){
        tmp=cnt[i]*op[i].d;
        add[op[i].a]+=tmp;
        add[op[i].b+1]-=tmp;
    }
    for(int i=2;i<=n;i++) add[i]+=add[i-1];
    for(int i=1;i<=n;++i){
         cout<<arr[i]+add[i]<<" ";
    } 
}