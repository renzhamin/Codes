#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		ll n;cin>>n;
		cout<<"Case "<<T++<<": ";
		if((n&&!(n&(n-1))) || n&1) done("Impossible")			
		ll even=2;
		while(!(!(n%even) && ((n/even)&1LL))) even+=2LL;
		cout<<n/even<<" "<<even<<"\n";			
	}
}