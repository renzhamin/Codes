#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
#define In(x,y) for(int i=0;i<n;i++,rc=0){for(int j=0;j<m;j++){x}y}  
using namespace std;

int main(){
	bool c[100],r[100];
	memset(c,1,sizeof(c));
	memset(r,1,sizeof(r));
	
	int n,m,rc=0;cin>>n>>m;
	bool a[n][m];
	In(
		cin>>a[i][j];
		if(!a[i][j])
			c[j]=r[i]=0;
	,)

	bool s[n][m];
	In(
		s[i][j] = (c[j] && r[i]) && a[i][j];
		rc+=s[i][j];
		if(!(r[i]+c[j])&&a[i][j])
			done("NO")
	,	
		if((r[i] && !rc))
			done("NO")
	)

	
	swap(n,m);
	In(
		rc+=s[j][i];
	,
		if(c[i] && !rc)
			done("NO")		
	)

	swap(n,m);
	cout<<"YES"<<"\n";
	In(
		cout<<s[i][j]<<" ";
	,cout<<"\n";)
}