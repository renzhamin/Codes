#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		int n;cin>>n;
		string s;cin>>s;
		ll st=0,more=0,p;
		if(s[0]=='0') more++,st=1;
		st+=(s[0]-48);
		for(int i=1;i<=n;++i){
			p=s[i]-48;
			if(p==0) continue;
			if(i>st){
				more+=(i-st);
				st+=(i-st);
			}
			st+=p;	
		}
		cout<<"Case #"<<T++<<": ";
		cout<<more<<"\n";
	}
}