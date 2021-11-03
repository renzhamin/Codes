#include <iostream>
using namespace std;
int main(){
	string s;cin>>s;
	bool f=0;
	int n=s.length();
	string o;
	for(int i=0;i<n;i++){
		if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
			if(f) { 
				cout<<" ";
				f=0;
			}
			i+=2;
		} else {
			cout<<s[i];
			f=1;
		}
	}
}