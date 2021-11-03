#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool ss(string &a,string &b){
	return a.length()>b.length();
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,T=1;cin>>t;
	while(t--){
		set<string>track;
		cin>>n;
		bool no=0;
		string s[n];
		for(int i=0;i<n;i++){ cin>>s[i]; track.insert(s[i]); }
		sort(s,s+n,ss);
	
		for(int i=0;i<n;i++){
			string ch;
			for(int j=0;j<s[i].length();j++){
				ch+=s[i][j];
				if(track.find(ch)!=track.end() && ch.length()<s[i].length()){
					no=1;
					break;
				}
			}
		}
	
		if(no)
			cout<<"Case "<<T++<<": "<<"NO"<<endl;
		else 
			cout<<"Case "<<T++<<": "<<"YES"<<endl;
	}
}