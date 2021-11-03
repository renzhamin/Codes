#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,start,end,i;cin>>t;
	while(t--){
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++) cin>>arr[i];
		start=0;
		for(int i=1;i<=n;i++) if(arr[i]) {start=i;break;}
		for(i=start+1;i<=n;i++){
			if(arr[i]){
				if(i-start<6) break;
				else start=i;
			}
		}
		if(i>n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
}