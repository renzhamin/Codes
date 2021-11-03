#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll M=(ll)1e9+7;

ll sum(ll n){
	return n*(n+1LL)/2LL;
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,k,ans=0;cin>>n>>k;
	for(int i=k;i<=n;++i){
		ll l=sum(i-1);
		ll r=sum(n)-sum(n-i);
		ans+=(r-l+1);
	}
	ans++;
	ans=ans%M;
	cout<<ans<<"\n";
}