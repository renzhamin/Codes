#include <iostream>
using namespace std;

void iku(int n){
	cout<<n<<endl;
	if(n<=0) return;
	iku(n-5);
	cout<<n<<endl;
}


int main(){
	freopen("Output.txt","w",stdout);
	iku(16);
}
