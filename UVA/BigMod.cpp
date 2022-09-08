#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll BigMod(ll base,ll power,ll mod){
	ll result=1;
	while(power){
		if(power&1)
			result=(result*base)%mod;
		base=(base*base)%mod;
		power/=2;
	}
	return result;
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll a,b,m;
	while(cin>>a>>b>>m){
		cout<<BigMod(a,b,m)<<"\n";
	}
}