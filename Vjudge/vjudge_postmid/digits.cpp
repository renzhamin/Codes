#include <iostream>
using namespace std;
int main(){
	int n,b;
	cin>>n>>b;
	int s=0;
	while(n>0){
		n/=b;
		s++;		
	}
	cout<<s<<endl;
}	