#include <iostream>
using namespace std;
int csum[101];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s,t="";int ans=0; cin>>s;
	if(s[0]=='Q') csum[0]=1;
	for(int i=1;i<s.length();i++){
		csum[i]=csum[i-1]+(s[i]=='Q');
	}
	for(int i=1;i<s.length();i++){
		if(s[i]=='A')
			ans+=csum[i]*(csum[s.length()-1]-csum[i]);
	}
	cout<<ans<<endl;
}