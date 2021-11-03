#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n; long arr[n+1];arr[0]=0;
	for(int i=1;i<=n;i++) cin>>arr[i];
	cout<<arr[2]-arr[1]<<" "<<arr[n]-arr[1]<<endl;
	for(int i=2;i<n;i++){
		cout<<min(arr[i]-arr[i-1],arr[i+1]-arr[i])<<" "
				<<max(arr[i]-arr[1],arr[n]-arr[i])<<endl;
	}
	cout<<arr[n]-arr[n-1]<<" "<<arr[n]-arr[1];
}