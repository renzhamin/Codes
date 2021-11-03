#include <iostream>
using namespace std;
 
int n, zero, one;
string s;
 
int main(){
	cin>>n>>s;
	
	for(int i=0; i<n; i++){
		if(s[i]=='0') zero++;
		else one++;
	}
	
	if(zero!=one) cout<<1<<endl<<s<<endl;
	else cout<<2<<endl<<s[0]<<" "<<s.substr(1, n-1)<<endl;
	
}