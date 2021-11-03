#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,m,ans;
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		long long arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n,greater<long long>());
		ans=*min_element(arr,arr+m);
		cout<<ans<<"\n";
	}
}