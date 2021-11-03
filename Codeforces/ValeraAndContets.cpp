#include <bits/stdc++.h>
#define ll long long
#define ld long double 
using namespace std;


void sum(ll p,ll g){
	ll s=0;
	if(!p) return;
	ll av=g/p;
	ll r=g%p;
	for(int i=0;i<p;i++,r--) {
		s+=av+(r>0);
		cout<<av+(r>0)<<" ";
	}

}


int main(){
	ll n,k,l,r,sk,sa;
	cin>>n>>k>>l>>r>>sa>>sk;
	sum(n-k,sa-sk);
	sum(k,sk);
}