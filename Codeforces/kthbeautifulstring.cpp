#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

int main(){
	ld t,n,k;cin>>t;
	while(t--){
		cin>>n>>k;
		ll e = ceil((-1+sqrt(1+8*k))/2.0);
		string s=string(n,'a');
		ll b = n-e-1;
		s[b]=s[b+e*(e+1)/2-k+1]='b';
		cout<<s<<"\n";	
	}
}