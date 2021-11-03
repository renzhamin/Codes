#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

const int mx=(int)1e6;
bool isprime[mx+1]; 

void sieve(){
	memset(isprime,1,sizeof(isprime));
	int n=sqrt(mx)+1;
	isprime[0]=isprime[1]=0;
	for(int i=2;i<=n;i++){
		if(isprime[i])
			for(int j=i*i;j<=mx;j+=i)
				isprime[j]=0;		
	}
	// for(int i=2;i<=mx;i++) if(isprime[i]) primes[primeno++]=i; 
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	string np=" is not prime.";
	string em=" is emirp.";
	string pr=" is prime.";
	string s;
	while(cin>>s){
		string sr=s; reverse(sr.begin(),sr.end());
		ll n1=stoll(s),n2=stoll(sr);
		if(isprime[n1] && isprime[n2] && n1!=n2) done(s+em)
		if(isprime[n1]) done(s+pr)
		done(s+np)
	}	
}