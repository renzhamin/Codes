#include <iostream>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
	int n,s,i;
	cin>>n;
	if(n==1){
		cout << 1 << endl;
	} else {
	
	for(i=0;i<n;i++){
	
		s=i*i;
		if(s>n){
			break;
		}
	  
	}
	cout << i-1 << endl;
	}
  }
}
