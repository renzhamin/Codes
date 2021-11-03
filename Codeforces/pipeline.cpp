#include <iostream>
#include <cmath>
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

long long findn(long long x){
	return (-1LL+sqrt(1LL+8LL*x))/2LL;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,k,s,del;
	cin>>n>>k;
	if(n==1) done(0)
	s=k-1;
	del=(s*(s+1LL))/2LL+1LL-n;
	if(del<0) done(-1)
	if(del==0) done(k-1)
	long long x1=s,
			  x2=findn(del),
			  f=x1-x2;
	if(k<n && f==1) f++;
	
	cout<<f<<"\n";
}