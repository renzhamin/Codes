#include <bits/stdc++.h>
#define ll long long 
using namespace std;


const int mx=(int)1e6+7;
bool isprime[mx+1]; 
int primes[78600],primeno=0; //78600 for 1e6,664600 for 1e7,6303310 for 1e7+1e8

void sieve(){
	memset(isprime,1,sizeof(isprime));
	int n=sqrt(mx)+1;
	isprime[0]=isprime[1]=0;
	for(int i=2;i<n;i++){
		if(isprime[i])
			for(int j=i*i;j<=mx;j+=i)
				isprime[j]=0;		
	}
	for(int i=2;i<=mx;i++) if(isprime[i]) primes[primeno++]=i; 
}

int countdivisors(ll n){
	ll c,total=1;
	for(int i=0;i<primeno&&primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			c=1;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			total*=c;
		}
	}
	if(n>1) total<<=1;
	return total-1;
}



int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	int t,T=1;cin>>t;
	while(t--){
		ll n;cin>>n;
		cout<<"Case "<<T++<<": ";
		cout<<countdivisors(n)<<"\n";
	}
}