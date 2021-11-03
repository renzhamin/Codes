#include <iostream>
using namespace std;
int main(){
	int n,t,s;
	cin>>n>>t;
	
	if(n==1 && t>9) {cout<<-1;return 0;}
	
	if(t>9) s=2; else s=1;
	
	cout<<t; n-=s;
	while(n--) cout<<0;
}
