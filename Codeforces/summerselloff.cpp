#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool comp(pair<ll,ll>a,pair<ll,ll>b){
	return min(a.first*2,a.second)-min(a.first,a.second)>
		min(b.first*2,b.second)-min(b.first,b.second);
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,f;cin>>n>>f;
	pair<ll,ll>arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
	sort(arr,arr+n,comp);
	for(int i=0;i<f;i++) arr[i].first*=2LL;
	ll s=0;
	for(int i=0;i<n;++i){
		s+=(min(arr[i].first,arr[i].second)); 	
	} 
	cout<<s<<"\n";
}