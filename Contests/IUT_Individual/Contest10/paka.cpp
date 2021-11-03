#include <bits/stdc++.h>
#define done(x) {cout<<x;goto alldone;} 
#define ll long long 
using namespace std;

void m(char &s){
	if(s>='A' && s<='Z') s+=32;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s;
	getline(cin,s);
	while(1){
		char c=s[0];
		m(c);
		int n=s.length();
		for(int i=0;i<n;++i){
			m(s[i]);
		}
		for(int i=0;i<n;++i){
			if(s[i]==' ' && s[i+1]!=c)
				done("N")
		}
		done("Y")
		alldone:{
			getline(cin,s);
			if(s[0]=='*') break;
			cout<<"\n";
		}
	}	
}