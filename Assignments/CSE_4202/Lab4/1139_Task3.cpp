#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll mem[40];

ll fib(ll n){
    if(n<0) return 0;
    if(mem[n]!=-1) return mem[n];
    return mem[n]=fib(n-1)+fib(n-2)+fib(n-3);
}

int main(){
    memset(mem,-1,sizeof(mem));
    mem[1]=mem[2]=1;
    mem[0]=0;
    ll n; cin>>n;
    cout<<fib(n)<<"\n";
}