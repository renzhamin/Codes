#include <iostream>
#define YES {cout<<"YES"<<endl; continue;}
#define NO {cout<<"NO"<<endl;continue;}
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	unsigned long long a,b,n,s,t; cin>>t;
	while(t--){
		cin>>a>>b>>n>>s;
		if(a*n==s || a*n<=s && a*n+b>=s) YES
		if(a*n+b<s) NO

		if(a*n>s) a=s/n;
		if(a*n+b>=s) YES
		
		NO	
	}
}