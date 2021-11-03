#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		ll a,b,x,y;
		cin>>x>>y>>a>>b;
		ll d=abs(x-y),ans=0;
		if(2*a<=b){
			ans=a*(x+y);
		} else {
			ll x1=min(x,y),y1=max(x,y);
			ll ans1=a*d+b*x1;
			ll ans2=a*(x+y);
			ll ans3=y1*b+d*a;
			ans=min({ans1,ans2,ans3});
		}
		cout<<ans<<"\n";
	}
}