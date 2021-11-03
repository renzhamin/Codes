#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool comp(pair<ll,pair<ll,ll>>a,pair<ll,pair<ll,ll>>b){
	if(a.second.second==b.second.second)
		return a.first<b.first;
	return a.second.second>b.second.second;

}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,x,R=0,I=0;
	cin>>n>>x;
	pair<ll,pair<ll,ll>>arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
	sort(arr,arr+n,comp);
	for(int i=0;i<n;++i){
		I=I+arr[i].first*	
	}		
}