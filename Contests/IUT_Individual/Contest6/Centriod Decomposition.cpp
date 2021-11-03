#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long a,b,n;	
	int t;cin>>t;
	while(t--){
		cin>>a>>b>>n;
		if(a==b)
			cout<<1<<"\n";
		else
			cout<<n<<"\n";
	}
}