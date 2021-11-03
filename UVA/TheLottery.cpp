#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,arr[15],sum;

void sub(int i,ll num,int cnt){
    if(i==n){
        (cnt&1?sum+=m/num:sum-=m/num);
        return;
    }
    sub(i+1,num,cnt);
    sub(i+1,arr[i]*num/__gcd(num,arr[i]),cnt+1);
}


int main(){
    while(cin>>m>>n){
        sum=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        sub(0,1,1);
        cout<<sum<<"\n";
    }
}
