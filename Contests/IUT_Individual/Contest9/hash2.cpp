#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s,f="ABC"; cin>>s;
	int n=s.length(),k=3,ans=0;
	if(n<3) done(0)
	if(n==3)if(s=="ABC") done(1) else done(0)
	string hv="ABC";
	string cur;
	queue<string>q;
	for(int i=0;i<3;++i){
		q.push(s[i]);
	}
	if(q=="f") cout<<f<<"\n";
}