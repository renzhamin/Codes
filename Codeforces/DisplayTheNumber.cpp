#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,i;cin>>t;
	while(t--){
		int seg;cin>>seg;
		if(seg&1)
			cout<<7,i=1;
		else
			i=0;
		for(;i<seg/2;i++) cout<<1;
		cout<<endl;
	}
}