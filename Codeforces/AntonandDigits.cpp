#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int two,three,five,six;
	cin>>two>>three>>five>>six;
	int big=min(two,min(five,six));
	two-=big; 
	int sm=min(two,three);
	cout<<256*big+32*sm<<endl;
}