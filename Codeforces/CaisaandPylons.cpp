#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n;cin>>n;
	ll arr[n+1],E=0,Pay=0;
	for(int i=0;i<n;i++) cin>>arr[i];	
	for(int i=0;i<n-1;++i){
		ll tmp=arr[i]-arr[i+1];
		E+=tmp;
		if(E<0)
			Pay-=E,E=0;
	}
	cout<<Pay+arr[0]<<"\n";
}