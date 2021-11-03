#include <iostream>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
	int n,i;cin>>n;
	for(i=2;i<=n;i++){
		if(n%i==0)
			break;
	}
	if(i!=n)
	   cout<<"no"<<endl;
	else
	   cout<<"yes"<<endl;
  }
}

