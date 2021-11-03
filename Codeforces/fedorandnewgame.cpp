#include <iostream>
using namespace std;

int countsetbits(int n){
	int c=0;
	while(n){
		if(n&1) c++;
		n=n>>1;
	}
	return c;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int arr[m+1];
	for(int i=0;i<=m;i++) cin>>arr[i];
	for(int i=0;i<m;i++) if(countsetbits(arr[i]^arr[m])<=k) ans++;
	cout<<ans<<endl;
}