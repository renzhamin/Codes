#include <bits/stdc++.h>
#define ll long long
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

const int mx=(int)1e7;
bool isprime[mx+1]; 
int primes[664700],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

void sieve(){
    memset(isprime,1,sizeof(isprime));
    int n=sqrt(mx)+1;
    isprime[0]=isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i])
            for(int j=i*i;j<=mx;j+=i)
                isprime[j]=0;        
    }
    for(int i=2;i<=mx;i++) if(isprime[i]) primes[primeno++]=i; 
}

bool fn(ll n,ll &a,ll &b){
    for(int i=0;i<primeno;i++){
        if(n-primes[i]<0) return 0;
        if(isprime[n-primes[i]]){
            a=primes[i],b=n-primes[i];
            return 1;
        }
    } 
}

int main(){
    sieve();
    ll n;
    while(cin>>n){
        if(n<8) done("Impossible.")
        ll a,b,c,d,i;
        for(i=4;!fn(n-i,a,b);i++);
        fn(i,c,d);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    }
}