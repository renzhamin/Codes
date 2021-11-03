#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

const int mx=1299709;
bool isprime[mx+1]; 
int primes[100001],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

ll lqa(int *arr,int n,int value){
	int i=lower_bound(arr,arr+n,value)-arr;
	if(i==0 && arr[i]>value) return -1;
	if(i==n) i--;
	if(arr[i]>value && i) i--;	
	return i;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	sieve();
	int n;
	while(cin>>n && n){
		if(isprime[n]) done(0)
		int l=primes[lqa(primes,primeno,n)];
		int r=*upper_bound(primes,primes+primeno,n);
		cout<<r-l<<"\n";
	}
}