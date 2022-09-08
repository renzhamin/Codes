#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,t,lo,hi;
ll coins[50],tables[20],h[20][2];

void sub(ll i,ll lcm,ll cnt=0){
    if(cnt==4){
        for(int i=0;i<t;++i){
            lo=tables[i]/lcm*lcm,
            hi=ceil(tables[i]/(long double)lcm)*lcm;
            if(fabs(tables[i]-lo)<fabs(h[i][0]-tables[i]))
                h[i][0]=lo;
            if(fabs(tables[i]-hi)<fabs(h[i][1]-tables[i]))
                h[i][1]=hi;
            }
        return;
    }
    sub(i+1,lcm/__gcd(lcm,coins[i])*coins[i],cnt+1);
    if(cnt+n-i>4)
        sub(i+1,lcm,cnt);
}


int main(){
    while(cin>>n>>t && (n+t)){
        for(int i=0;i<n;i++) cin>>coins[i];
        for(int i=0;i<t;i++) cin>>tables[i],h[i][0]=1e12,h[i][1]=1e12;
        sub(0,1);            
        for(int i=0;i<t;i++){
            cout<<h[i][0]<<" "<<h[i][1]<<"\n";
        } 
    }
}