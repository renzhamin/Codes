#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e6;
bool isprime[mx+1]; 
int primes[78600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

void countdivisors(ll n){
	ll c,total=1,N=n;	
	for(int i=0;primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			c=1;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			total*=c;
			cout<<primes[i]<<"^"<<c-1<<" * ";
		}
	}
	if(n>1) {
		total<<=1;
		cout<<n;
	}
	cout<<"\n";
}


int main(){
	sieve();
	ll n;
	while(cin>>n) countdivisors(n);
}