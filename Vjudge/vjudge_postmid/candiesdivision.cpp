#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	long long n,m,a,b;
	while(t--){
		cin>>n>>m;
		a=n/m*m;
		b=n-a;
		cout<<a+min(b,m/2)<<endl;
	}
}