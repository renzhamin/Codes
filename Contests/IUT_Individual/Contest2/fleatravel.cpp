#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i*=2)
			if(i==n) {
				cout<<"YES"<<endl;
				goto done;
			}
		cout<<"NO"<<endl;
		done:;
	}
}