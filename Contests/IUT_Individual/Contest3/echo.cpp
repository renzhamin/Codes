#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long int t,T=1;cin>>t;
	while(t--){
		unsigned long long x,y;cin>>y;
		x=(10*y)/9;
		cout<<"Case "<<T++<<": ";
		if(y%9==0)
			cout<<x-1<<" ";
		cout<<x<<endl;
	}
}