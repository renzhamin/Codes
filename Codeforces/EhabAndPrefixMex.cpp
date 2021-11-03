#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n],ans[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		if(arr[0]!=0 && arr[0]!=1) done(-1)			
		bool isrep=0;
		ans[0]=1^arr[0];

		int i=1;
		bool fail=0;
		while(i<n){
			if(arr[i]==arr[i-1]){
				int c=i;
				while(c<n && arr[c]!=arr[i]) c++;

				int d=c-i+1;
				if(arr[c]-arr[i]>d) {
					fail=1;break;
				}
				int df=arr[c]-arr[i];
				int k=d-df;
				while(k-->=0) ans[i]=ans[i-1],i++;
				k=d-df;
				while(k--) ans[i]=ans[i-1]+1,i++;
				if(i<n) ans[i]=arr[i];

			} else if(arr[i]==arr[i-1]+1){
				ans[i]=ans[i-1]+1;
			} else if(arr[i]==arr[i-1]+2 && i==1){
				ans[i]=ans[i-1]-1;
			} else {
				fail=1;
				break;
			}
			i++;
		}
		if(fail) done(-1)
		for(auto i:ans) cout<<i<<" "; 
		cout<<"\n";
	}
}