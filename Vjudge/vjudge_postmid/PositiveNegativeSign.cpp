#include <iostream>
using namespace std;
int main(){
	long long n,m,t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		cout<<"Case "<<i<<": "<<n/2*m<<endl;
	}
}