#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int t;cin>>t;
	string s="Case ";
	for(int i=1;i<=t;i++){
		long long r1,r2,c1,c2;
		cin>>r1>>c1>>r2>>c2;
		long long d1=abs(r1-r2),d2=abs(c1-c2);
		if(d1==d2) cout<<s<<i<<": "<<1<<endl;
		else if(abs(d1-d2)%2==0) cout<<s<<i<<": "<<2<<endl;
		else cout<<s<<i<<": "<<"impossible"<<endl;
	}
}