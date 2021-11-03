#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		string pattern;cin>>pattern;
		string text=pattern;
		reverse(pattern.begin(),pattern.end());
		int n = text.length();
		int i=n-1,j=n-1;
		cout<<"Case "<<T++<<": ";
		if(text==pattern) done(n)
		//pattern j ----- text i //
		while(j>=0){
			if(pattern[j]==text[i]){
				i--,j--;
			} else {
				i=n-1,j--;
			}
		} 
		cout<<n+i+1<<"\n";
	}
}