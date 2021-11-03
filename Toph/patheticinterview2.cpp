#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,x,y,s=0;cin>>n;
	while(n>5){
		x=sqrt(n); y=n/x;
		n-=(x*y);
		s+=(x+y);
	}
	cout<<s+n<<endl;
}