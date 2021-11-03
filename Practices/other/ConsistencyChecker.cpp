e#include <iostream>
#include <algorithm>
using namespace std;

bool sbl(string &a,string &b){
	return a.length()<b.length();
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=0;cin>>t;
	while(t--){
		int n;cin>>n; string s[n];
		for(int i=0;i<n;i++) cin>>s[i];
		sort(s,s+n);
		cout<<"Case "<<++T<<": ";
		for(int i=0;i<n;i++){
			int l=s[i].length();
			for(int j=i+1;j<s[j].length();j++){
				string sub=s[j].substr(0,l);
				if(sub==s[i]){
					cout<<"NO"<<endl;
					goto done;
				}
			}
		}
		cout<<"YES"<<endl;
		done:;
	}
}