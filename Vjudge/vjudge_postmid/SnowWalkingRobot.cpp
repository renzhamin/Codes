#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;while(t--){	
		string s;cin>>s;
		int l,r,u,d;l=r=u=d=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='U') u++;
			else if(s[i]=='D') d++;
			else if(s[i]=='L') l++;
			else if(s[i]=='R') r++;
		}
		if(l>r) l=r; else r=l;
		if(d>u) d=u; else u=d;
		
		if(d==0) {
			l=min(l,1);r=min(r,1);
		}
		if(l==0) {
			d=min(d,1);u=min(u,1);
		}
		cout<<l+r+u+d<<endl;	
		while(l--) cout<<"L";
		while(d--) cout<<"D";
		while(r--) cout<<"R";
		while(u--) cout<<"U";
		cout<<endl;
	}
}