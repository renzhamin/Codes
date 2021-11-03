#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool br[100],bc[100];

int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif

	int t;cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		int s[n+1][m+1]{};
		string ans;
		
		memset(br,0,sizeof(br));
		memset(bc,0,sizeof(bc));		

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>s[i][j];
			}
		}

		for(int i=0;i<n;i++){
		 	for(int j=0;j<m;j++){
		 		if(s[i][j]==1){
		 			br[i]=1;
		 			bc[j]=1;
		 		}
		 	}
		 }

		 ll a = 0;
		 for(int i=0;i<n;i++){
		 	for(int j=0;j<m;j++){
		 		if(br[i]!=1 && bc[j]!=1) {
		 			br[i]=1;
		 			bc[j]=1;
		 			a++;
		 			break;
		 		}
		 	}
		 }

		 if(a&1)
		 	ans="Ashish";
		 else
		 	ans="Vivek";


		 cout<<ans<<"\n";
	}
}