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

ll countdivisors(ll n){
	ll i=0,N=n;	
	for(i=0;primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			while(n%primes[i]==0){
				n/=primes[i];
			}
		}
	}
	if(n>1) return n;
	return primes[i]%N==0?primes[i]:primes[i-1];
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();	
	int t,tp,T=1;cin>>t;
	while(t--){
		ll n=1,tmp;
		cin>>tp;
		cout<<"Case #"<<T++<<": ";
		while(tp--) cin>>tmp,n*=tmp;		
		cout<<countdivisors(n+1)<<"\n"; 
	}
}