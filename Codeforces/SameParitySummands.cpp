#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(k>n) done("NO")	
		ll xo=n-k+1;
		if(xo>0 && xo&1){
			cout<<"YES"<<"\n";
			for(int i=0;i<k-1;i++) cout<<1<<" ";
			done(xo)
		}
		ll xe=n-(k-1)*2LL;
		if(xe<=0 || xe&1) done("NO")
		cout<<"YES"<<"\n";
		for(int i=0;i<k-1;i++) cout<<2<<" ";
		cout<<xe<<"\n"; 	
	}	
}