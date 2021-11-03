#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,team;cin>>t;
	while(t--){
		cin>>n; int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		int f;
		for(f=0;f<n-1;f++) if(arr[f+1]==arr[f]+1) break;
		if(f==n-1) team=1;
		else team=2;		
		cout<<team<<endl;
	}
}