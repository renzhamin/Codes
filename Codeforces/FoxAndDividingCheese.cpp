#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

const ll mx=(ll)1e6;
bool isprime[mx+1]; 
ll primes[78600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

ll ad[40000],bd[40000],ra,rb;

void countdivisors(ll *arr,ll n,ll &r){
    ll c;
    for(int i=0;primes[i]*primes[i]<=n && i<primeno;++i){
        if(n%primes[i]==0){
            c=0;
            while(n%primes[i]==0){
                n/=primes[i];
                c++;
            }
            arr[primes[i]]=c;
        }
    }
    if(n<40000) arr[n]=1;
    else r=n;
}


int main(){
    sieve();    
    ll a,b,s=0;
    cin>>a>>b;
    if(a==b) done(0)
    countdivisors(ad,a,ra),countdivisors(bd,b,rb);
    for(int i=2;i<6;i++)s+=(abs(ad[i]-bd[i]));
    for(int i=6;i<40000;i++)
        if(ad[i]-bd[i]!=0) done(-1)
    if(ra!=rb) done(-1)
    done(s)
}