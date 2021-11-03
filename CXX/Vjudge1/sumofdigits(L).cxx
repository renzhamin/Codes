#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
	int n1;cin>>n1;
	int s=0;
	int r;
	while(n1!=0){
		r=n1%10;
		s+=r;
		n1/=10;
	}
	cout<<s<<endl;
	}
}