#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n;
	int t;cin>>t;
	while(t--){
		cin>>n;
		ll d=n/2;
		if(d&1) done("NO")
		ll e=2,o=1,es=0,os=0;
		cout<<"YES"<<"\n";
		for(int i=0;i<d;i++,e+=2) {cout<<e<<" ";es+=e;} 
		for(int i=0;i<d-1;i++,o+=2) {cout<<o<<" ";os+=o;}
		cout<<es-os<<"\n";
	}
}