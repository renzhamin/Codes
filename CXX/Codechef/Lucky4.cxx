#include <iostream>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
	int n,c,s=0;
	cin>>n;
	while(n!=0){
		c=n%10;
		if(c==4){
		  s++;
		}
		n/=10;
	}
	cout << s << endl;
 }	
}
