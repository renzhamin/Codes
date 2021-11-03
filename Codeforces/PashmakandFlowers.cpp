#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n;cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	long long mx=arr[n-1],mn=arr[0],ans,nmx,nmn;
	if(mx==mn)
		ans=n*(n-1)/2;
	else{
		nmx=count(arr,arr+n,mx);
		nmn=count(arr,arr+n,mn);
		ans=nmx*nmn;
	}
	cout<<mx-mn<<" "<<ans<<endl;
}	