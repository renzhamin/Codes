#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	ll n;
	int t;cin>>t;
	while(t--){
		cin>>n;
		ll x,ans,i=2;
		while(1){
			x=1LL<<i;
			x--;
			ans=n/x;
			// cout<<x<<"\n";

			if(n%x==0){
				cout<<ans<<"\n";
				break;
			}
			i++;
		}
	}
}