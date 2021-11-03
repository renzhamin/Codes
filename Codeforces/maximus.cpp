#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,x;cin>>n;int arr[n],a[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	a[0]=arr[0];
	x=-1;
	for(int i=1;i<n;i++){
		x=max(x,a[i-1]);
		a[i]=arr[i]+x;
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}