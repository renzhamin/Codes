#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,i1,i2,end;
	int t;cin>>t;
	string s;
	while(t--){
		cin>>n;
		long long arr[n],a[n],b[n];
	
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		i1=n/2-1,i2=n/2,end=n/2;
		if(n&1) i1=n/2,i2=n/2+1,end++;
		for(int i=0;i1>=0;i++,i1--) a[i]=arr[i1];
		for(int i=0;i2<n;i++,i2++) b[i]=arr[i2];  
		for(int i=0;i<n/2;++i){
			cout<<a[i]<<" "<<b[i]<<" ";
		}
		if(n&1) cout<<a[n/2];
		cout<<endl;
	}
}