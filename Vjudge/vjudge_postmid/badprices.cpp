#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;while(t--){
		int n,rmin=1000010,s;
		cin>>n;
		s=0;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=n-1;i>-1;i--){
			rmin=min(rmin,arr[i]);
			if(arr[i]>rmin) s++;
		}
		cout<<s<<endl;
	}
}