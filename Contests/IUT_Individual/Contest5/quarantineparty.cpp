#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,x;cin>>n;
	n++;
	if(n&1) x=n; else x=n/2;
	if(n==1) x=0;
	cout<<x<<endl;
}