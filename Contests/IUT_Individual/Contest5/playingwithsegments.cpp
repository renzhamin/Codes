#include <iostream>
#define done(n) {cout<<n;return 0;}
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int minimum=arr[0],maximum=arr[0];
	for(int i=0;i<n;i++){
		minimum=min(minimum,arr[i]);
		maximum=max(maximum,arr[i]);
	}
	if(k==1) done(minimum);
	if(k==2) done(max(arr[0],arr[n-1]));
	done(maximum);
}