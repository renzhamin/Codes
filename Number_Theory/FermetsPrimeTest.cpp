#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll mulmod(ll a,ll b,ll mod){
    ll result = 0; a%=mod;
    while(b){
        if(b&1) 
        	result = (result+a)%mod ;
        a=(a*2)%mod;
        b/=2;
    }
    return result%mod ;
}

ll BigMod(ll base,ll power,ll mod){
	ll result=1;
	while(power){
		if(power&1LL)
			result=mulmod((__int128)result,base,mod);
		base=mulmod(base,base,mod);
		power>>=1LL;
	}
	return result;
}



bool isprime(ll n,int trial=10){

	if(n<5) return n==2 || n==3;
	if(!(n&1)) return 0;

	for(int i=0;i<trial;++i){
		ll base = 1+rand()%(n-1);
		ll check = BigMod(base,n-1,n);
		if(check!=1) return 0;
	}
	return 1;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		cout<<(isprime(n)?"YES\n":"NO\n");	
	}
}
