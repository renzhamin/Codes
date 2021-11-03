#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll csum[31];csum[0]=0;
	for(ll i=1;i<=30;++i){
		ll tmp=1LL<<i;
		csum[i]=csum[i-1]+tmp;
	}
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll h=n/2;
		ll a=csum[n]-csum[n-1]+csum[h-1];
		ll b=csum[n-1]-csum[h-1];
		cout<<abs(a-b)<<"\n";
	}
}