#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n;cin>>t;
	while(t--){
		cin>>n;
		int a[n],b[n],d,l1=-1,l2=-1;
		bool f=1;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i];
		for(int i=0;i<n;++i){
			l1=max(l1,a[i]),l2=max(l2,b[i]);
			if(a[i]<l2 || a[i]<l1 || b[i]<l2){
				f=0;
				break;
			}
			if(i){
				d=a[i]-a[i-1];
				if(b[i]-b[i-1]>d){
					f=0;
					break;
				}
			}
		}
		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}