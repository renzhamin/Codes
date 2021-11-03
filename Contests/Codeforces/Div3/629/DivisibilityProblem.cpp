#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		double a,b;
		cin>>a>>b;
		cout<<b*ceil(a/b)-a<<endl;
	}
}