#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)2e7+1;
bool isprime[mx+1]; 
int primes[1270617],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

int main(){
    sieve();
    int arr[200000],l=1;
    for(int i=3;i<mx-2;++i){
        if(isprime[i] && isprime[i+2])
            arr[l++]=i;
    }
    int n;
    while(cin>>n){
        cout<<"("<<arr[n]<<", "<<arr[n]+2<<")"<<"\n";
    }
}