#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,a,b; cin>>n>>a>>b;
	int r=n-(a+b+1);
	cout<<n-a-max(0,r)<<endl;
}