#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,mn,mx,df;
	int t;cin>>t;
	while(t--){
		cin>>n;
		long long arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int i=0;
		for(i=0;i<n-1,arr[i]<arr[i+1];++i)
		if(i==n-1){cout<<0<<"\n";continue;}
		i++;
		mn=arr[i],mx=arr[i-1],df=-1;
		for(;i<n;++i){
			mn=min(mn,arr[i]),mx=max(max,arr[i])
			df=max(df,mx-mn)
		}

	}
}