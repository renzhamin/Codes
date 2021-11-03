#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s; cin>>s;
	int n=s.length()-1;
	int x=(s[n-1]-48)*10+(s[n]-48);	
	int ans=0;
	if(x%4==0){
		ans=4;
	}
	cout<<ans<<"\n";
}