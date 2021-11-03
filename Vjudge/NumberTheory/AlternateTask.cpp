#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e4;
bool isprime[mx+1]; 
int primes[mx],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

int ans[mx+1];
void countdivisors(int n){
	int c,total=1,N=n;	
	for(int i=0;primes[i]*primes[i]<=n;++i){
		if(n%primes[i]==0){
			c=1;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			total*=(powl(primes[i],c)-1)/(primes[i]-1);
		}
	}
	if(n>1) total*=(n*n-1)/(n-1);
	ans[total]=N;
}



int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int T=1;ll n;
	sieve();
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=1000;++i){
		countdivisors(i);
	}
	while(cin>>n && n){
		cout<<"Case "<<T++<<": ";
		cout<<ans[n]<<"\n";
	}

}
