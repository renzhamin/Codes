#include <iostream>
#include <algorithm>
#include <numeric>
#define ll long long
using namespace std;


bool check(ll *arr,ll n,ll f,ll mid){
	ll fs=0;
	for(int i=0;i<n&&fs<f;i++) 
		fs+=(arr[i]/mid);

	return fs>=f;
}


ll bs(ll *arr,ll n,ll f){
	ll low=1LL,mid,
	   high=arr[0];
	
	while(low<high){
		mid=(high+low+1LL)/2LL;
		if(check(arr,n,f,mid))
			low=mid;
		else
			high=mid-1LL;
	}
	return low;
}



int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,f,ans;
	int t;cin>>t;
	while(t--){
		cin>>n>>f;
		ll arr[n],x=0;
		for(int i=0;i<n;i++) cin>>arr[i],x+=arr[i];
		
		if(x<f) {cout<<0<<"\n";continue;}
		
		sort(arr,arr+n,greater<ll>());
		
		cout<<bs(arr,n,f)<<"\n";
	}
}