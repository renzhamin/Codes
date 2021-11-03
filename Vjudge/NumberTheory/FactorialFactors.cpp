#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e6;
bool isprime[mx+1]; 
int primes[78600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8
int ans[mx+1];

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

ll primefactors(ll &n,ll prime){
	ll s=0;
	while(n%prime==0){
		s++;
		n/=prime;
	}
	return s;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();	
	for(ll i=2;i<=mx;++i){
		ll n=i; 
		ans[i]=ans[i-1];
		for(int j=0;j<primeno&&primes[j]*primes[j]<=n;++j){
			ans[i]+=primefactors(n,primes[j]);
		}
		if(n>1) ans[i]++;
	}

	ll n;
	while(cin>>n){
		cout<<ans[n]<<"\n";
	}
}