#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e6;
bool isprime[mx+1]; 
ll primes[78600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8
ll M=1000000007;

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

ll BigMod(ll base,ll power,ll mod){
	ll result=1;
	while(power){
		if(power&1)
			result=(result*base)%mod;
		base=(base*base)%mod;
		power>>=1LL;
	}
	return result;
}

ll countdivisors(ll n,ll m){
	if(n<0) return 1;
	ll c,total=1,N=n,inv;	
	for(int i=0;i<primeno&&primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			c=0;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			c*=m;c++;
			inv = (BigMod(primes[i]-1LL,M-2LL,M))%M;
			total*=((BigMod(primes[i],c,M)-1LL)%M*inv)%M;
			total%=M;
		}
	}
	c=m+1;
	inv = (BigMod(n-1LL,M-2LL,M))%M;
	if(n>1) total*=((BigMod(n,c,M)-1LL)%M*inv)%M;
	return total%M;
}


int main(){
	sieve();
	int t,T=1;cin>>t;
	while(t--){
		ll n,m;cin>>n>>m;
		cout<<"Case "<<T++<<": ";
		cout<<countdivisors(n,m)<<"\n";
	}
}