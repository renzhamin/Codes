#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=32700;
bool isprime[mx+1]; 
int primes[3600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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



void generate(ll l,ll r){
	bool ip[r-l+1];
	memset(ip,1,sizeof(ip));
	int n=sqrt(r)+1;
	if(l==1) ip[0]=0;
	for(int i=0;i<primeno&&primes[i]<n;i++){
		ll x=(l/primes[i])*primes[i];
		ll start=x+(x<l?primes[i]:0);
		for(ll j=start;j<=r;j+=primes[i])
			ip[j-l]=0;
		if(start==primes[i]) ip[start-l]=1;
	}
	for(int i=l;i<=r;i++) if(ip[i-l]) cout<<i<<"\n"; 
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	int t;cin>>t;
	while(t--){
		ll a,b;cin>>a>>b;
		generate(a,b);
		cout<<"\n";
	}
}