#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		ll n,m;cin>>n>>m;
		ll ans = (n/2LL)*m;
		if(n&1) ans += ceil((double)m/2LL);
		cout<<ans<<"\n";
	}
}