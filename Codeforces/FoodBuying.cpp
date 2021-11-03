#include <iostream>
typedef long long lli;
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	lli b;
	cin>>b;
	lli s=0;
	lli num=b;
	lli r;
	while(b>0){
		if(b<10){s+=b;break;}
		r=b%10;
		s+=(b-r);
		b=r+b/10;
	}
	cout<<s<<endl;
	}
}