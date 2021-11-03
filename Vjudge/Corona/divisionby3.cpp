#include <iostream>
using namespace std;

int s(int n){
	return n/3*2+(n%3==2?1:0);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,a,b,T=0;cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<"Case "<<++T<<": "<<s(b)-s(a-1)<<endl;
	}
}