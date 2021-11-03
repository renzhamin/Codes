#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

string ans;
bool b=1;

ll process(string s){
	bool o=0;
	int n=s.length();
	for(int i=0;i<n;++i){
		if((s[i]=='1'&&o) || s[i]-48>1){
			ans=s;
			b=0;
			return 0;
		}
		if(s[i]=='1')o=1;
	}
	return n-1;
}

int main(){
	int n,zero=0;cin>>n;
	string s[n];
	bool z=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]=="0") z=1;
		zero+=process(s[i]);
	}
	if(z)done(0)
	if(b)ans="1";
	cout<<ans+string(zero,'0')<<"\n";

}