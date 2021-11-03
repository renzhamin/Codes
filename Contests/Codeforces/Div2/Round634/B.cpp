#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long x,div,mn;
	int t;cin>>t;
	while(t--){
		cin>>x>>div>>mn;
		while(x>20 && div){
			x=x/2+10;
			div--;
		}
		while(x && mn){
			x=x-10;
			mn--;
		}
		if(x<=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}