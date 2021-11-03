#include <bits/stdc++.h>
#define ll long long
#define done(x) {cout<<x<<"\n";return 0;}  
using namespace std;


int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	ll n;cin>>n;
	if(n==1) done(1)
	if(n==2) done(2)
	if(n==3) done(6)
	if(n==4) done(12)

	if(n&1) done(n*(n-1)*(n-2))
		
	done((n%3?(n*(n-1)*(n-3)):((n-1)*(n-2)*(n-3))))
	
}