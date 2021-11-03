#include <iostream>
#define n 10000
using namespace std;
int main(){
	int i,s=0;
	int sum;cin>>sum;
	for(i=1;i<=n && s<sum;i++){
		s+=(i*(i+1))/2;
		if(s==sum) break;
		if(s>sum) {i--;break;}
		// cout<<"S at "<<i<<" "<<s<<endl;
	}
	cout<<i;
}