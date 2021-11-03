#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;

ll div1[(ll)1e6],div2[(ll)1e6];
ll i1=0,i2=0;


void dc(ll n){
	ll val = sqrt(n)+1,tmp;
	for(ll i=1;i<val;++i){
		if(n%i) continue;
		div1[i1++] = i;
		tmp = n/i;
		if(tmp!=i) div2[i2++] = tmp;
	}
}



int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	ll n,k;
	cin>>n>>k;
	dc(n);
	if(i1+i2<k) done(-1)
	if(k<=i1) done(div1[k-1]);
	done(div2[i2+i1-k]);
}