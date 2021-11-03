#include <iostream>
#define lli long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	lli n;
	int t;cin>>t;
	while(t--){
		cin>>n;
		lli x=(--n)/2;
		cout<<x<<"\n";
	}
}