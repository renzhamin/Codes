#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
	int n,s;
	cin>>n;
	while(n!=0){
		s=n%10;
		cout<<s;
		n/=10;
	}
	cout << endl;
  }
	
}
