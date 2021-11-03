#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,f1,fm1;cin>>t;
	while(t--){
		cin>>n;
		f1=fm1=n+1;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<n;i++) if(a[i]==1){f1=i;break;}
		for(int i=0;i<n;i++) if(a[i]==-1){fm1=i;break;} 
		bool f=1;
		for(int i=0;i<n;i++){
			if(a[i]==b[i])
				continue;
			if(b[i]>a[i] && i<=f1){f=0;break;}
			if(b[i]<a[i] && i<=fm1){f=0;break;}
		}
		if(f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
}