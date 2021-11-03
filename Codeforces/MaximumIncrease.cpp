#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n; long arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n==1) { cout<<1<<endl; return 0;}
	int i=0,j=0,ans=0;
	for(int i=1;i<n;i++){
		if(arr[i]-arr[i-1]<=0)
			j=i;
		ans=max(i-j+1,ans);
	}
	cout<<ans<<endl;
}