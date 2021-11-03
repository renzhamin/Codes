#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		ld n,m,x,y;
		cin>>n>>m>>x>>y;
		string s[(int)n];
		bool do2 = (y/2) < x;
		for(int i=0;i<n;i++) cin>>s[i];
		
		ll ans = 0;
		bool start=0;
		int st,en;
		for(int i=0;i<n;i++,start=0){
		 	for(int j=0;j<m;j++){
		 		char now=s[i][j];
		 		if(!start && now=='.')start=1,st=j;
		 		if(start && (now=='*' || (now=='.' && j==m-1))){
		 			start=0,en=j;
		 			ll dif=en-st;
		 			if(now!='*') dif++;
		 			if(do2){
		 				ans+=(dif/2)*y + (dif&1?x:0);
		 			} else {
		 				ans+=dif*x;
		 			}
		 		} 
		 	}
		}
		cout<<ans<<"\n"; 
	}

}