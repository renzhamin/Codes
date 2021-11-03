#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e7;
bool isprime[mx];
int primes[(int)1e6],primeno=0;

void sieve(){
	int n=sqrt(mx)+1;
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=0;
	for(int i=2;i<n;i++){
		if(isprime[i])
			for(int j=i*i;j<mx;j+=i)
				isprime[j]=0;		
	}
	for(int i=2;i<mx;i++) if(isprime[i]) primes[primeno++]=i; 
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	int t,T=1;cin>>t;
	while(t--){
		int n,s=0;cin>>n;
		int num=n;
		n/=2;
		for(int i=0;primes[i]<=n;++i){
			if(isprime[num-primes[i]])
				s++;
		}
		cout<<"Case "<<T++<<": ";
		cout<<s<<"\n";
	}
}