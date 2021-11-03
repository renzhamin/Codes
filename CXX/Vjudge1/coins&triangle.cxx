#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
	int i,s=0;
	int n;cin>>n;
	for(i=1;;i++){
		s+=i;
		if(s>n)
		  break;
	}
	cout << i-1 << endl;
	}
}