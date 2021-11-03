#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	ll arr[n+1],cs[n+1],css[n+1];cs[0]=css[0]=0;
	for(int i=0;i<n;i++) cin>>arr[i+1],cs[i+1]=cs[i]+arr[i+1];
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++) css[i]=css[i-1]+arr[i];
	ll m,l,r,t;cin>>m;
	while(m--){
		cin>>t>>l>>r;
		(t==1)?cout<<cs[r]-cs[l-1]<<"\n":cout<<css[r]-css[l-1]<<"\n";
	} 
}