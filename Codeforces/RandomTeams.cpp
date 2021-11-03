#include <iostream>
using namespace std;


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,m,mx,mn=0,r,div,a2;
	cin>>n>>m;
	mx=(n-m+1)*(n-m)/2,r=n%m,div=n/m;
	if(r==0){
		mn=(div*(div-1)/2)*m;
	} else {
		mn+=((div*(div-1))/2)*m;
		mn+=(r*div);
	}
	cout<<mn<<" "<<mx;
}