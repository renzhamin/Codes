#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll s,n;
	int t;cin>>t;
	while(t--){
		s=0;
		cin>>n;
		ll i=n/2;
		while(n>0 && i>0){
			s+=(4LL*(n-1)*i);
			i--,n-=2LL;
		}
		cout<<s<<"\n";
	}
}