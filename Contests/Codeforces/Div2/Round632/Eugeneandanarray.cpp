#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	int arr[n+1],cs1[n+2],cs2[n+2];
	cs1[0]=cs2[0]=cs1[n+1]=cs2[n+1]=0;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	for(int i=1;i<=n;i++) cs1[i]=cs1[i-1]+arr[i];
	for(int i=n;i>=1;i--) cs2[i]=cs2[i+1]+arr[i];
	int sub=0;
	for(int i=1;i<=n;i++) {
		if(!cs1[i])
			sub++;
		if(!cs2[i])
			sub++;
	}
	cout<<2*n-sub<<endl;
}