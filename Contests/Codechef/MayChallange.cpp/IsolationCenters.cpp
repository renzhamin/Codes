#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,q,c;
		ll freq[26]{};
		string s;
		cin>>n>>q>>s;
		for(int i=0;i<n;i++) freq[s[i]-'a']++;	
		while(q--){
			int s=0;
			cin>>c;
			for(int i=0;i<26;++i){
				ll d=freq[i]-c;
				if(d>0) s+=d;
			}
			cout<<s<<"\n";
		}
	}	
}