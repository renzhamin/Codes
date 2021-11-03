#include <iostream>
using namespace std;
int main(){
	freopen("tabs.in","r",stdin);
	//freopen("Output.txt","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;while(t--){
		int n,k;cin>>n>>k;
		if(n==1 && k==1)
			cout<<0<<endl;
		else if(k==1 || k==n)
			cout<<1<<endl;
		else
			cout<<2<<endl;	
	}
}