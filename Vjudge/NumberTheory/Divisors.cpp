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

void countdivisors(ll n,int *arr){
	ll c,div=1,N=n,divsum=1;	
	for(int i=0;primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			c=1;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			div*=c;
			divsum*=(powl(primes[i],c)-1)/(primes[i]-1);
		}
	}
	if(n>1) div<<=1,divsum*=((n*n-1)/(n-1));
	arr[0]=div,arr[1]=divsum;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	int t;cin>>t;
	while(t--){
		double a,b,k;
		cin>>a>>b>>k;
		ll sds=0,sdv=0;
		int arr[2];
		ll j=ceil(a/k),i=j*k;
		while(i<=b){
			countdivisors(i,arr);
			sdv+=arr[0],sds+=arr[1];
			j++,i=j*k;
		}
		cout<<sdv<<" "<<sds<<"\n";
	}
}