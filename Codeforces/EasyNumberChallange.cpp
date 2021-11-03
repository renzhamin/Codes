#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e6+1;
bool isprime[mx];
int primes[mx],primeno=0;
const ll M=1073741824;

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

int divs[mx+1];
void countdivisors(int N){
	int c,total=1,n=N;
	int val=sqrt(n)+1;
	
	for(int i=0;primes[i]<val;++i){
		if(n%primes[i]==0){
			c=1;
			while(n%primes[i]==0){
				n/=primes[i];
				c++;
			}
			total*=c;
			val=sqrt(n)+1;
		}
	}
	if(n>1) total<<=1;
	divs[N]=total;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	clock_t start,end;
	start=clock();
	sieve();
	for(int i=1;i<mx;i++) countdivisors(i); 
	ll a,b,c,ans=0;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			for(int k=1;k<=c;++k){
				ans+=divs[i*j*k];
			}
		}
	}
	cout<<ans<<"\n";
	end=clock();
	double time=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<setprecision(5)<<fixed<<time<<"\n";

}