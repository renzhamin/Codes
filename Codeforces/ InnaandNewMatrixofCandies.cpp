#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,m,g;
	cin>>n>>m;
	int mf[100000]{};
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];	
	for(int i=0;i<n;i++){
		bool f=0;
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
			 	mf[abs(j-g)]=1;
			 	break;
			}
			if(s[i][j]=='G'){
				f=1;
				g=j;
			}
		}
		if(!f) done(-1)
	}
	int ans=0;
	for(int i=0;i<m;i++) ans+=mf[i];
	cout<<ans<<"\n"; 
}