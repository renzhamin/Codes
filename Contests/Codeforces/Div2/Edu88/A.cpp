#include <bits/stdc++.h>
#define ld long double
#define done(x) {cout<<x<<"\n";continue;}  
using namespace std;
int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		ld n,m,k,ans;cin>>n>>m>>k;
		if(!m) done(0)
		if(n/k>=m) done(m)
		ld b=n/k;
		ld a=ceil((m-n/k)/(k-1));
		cout<<fabs(b-a)<<"\n";
	}

}