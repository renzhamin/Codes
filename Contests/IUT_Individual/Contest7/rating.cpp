#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n;cin>>n;
	ll arr[n+1],c[n+1],s=0;
	for(int i=0;i<n;i++) cin>>arr[i],c[i]=1;
	for(int i=1;i<n;i++)
		if(arr[i]>arr[i-1])
			c[i]=c[i-1]+1;
	for(int i=n-2;i>=0;--i)
	 	if(arr[i]>arr[i+1] && c[i]<=c[i+1])
	 		c[i]=c[i+1]+1;
	for(int i=0;i<n;i++) s+=c[i];
	cout<<s<<"\n";
}