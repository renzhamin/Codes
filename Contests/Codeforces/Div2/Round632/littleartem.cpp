#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,r,c;cin>>t;
	while(t--){
		cin>>r>>c;
		for(int i=0;i<c-1;i++) cout<<"B";cout<<"W"<<endl;
		for(int i=1;i<r;i++,cout<<endl)
			for(int j=0;j<c;j++)
				cout<<"B";			
	}
}