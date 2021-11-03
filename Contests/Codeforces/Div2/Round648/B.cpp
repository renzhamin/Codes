#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll a[n],b[n];
		bool o=0,z=0;

		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
		 	cin>>b[i];
		 	if(b[i]==1) o=1;
		 	else z=1;
		}	
		if(is_sorted(a,a+n)){
			cout<<"Yes"<<"\n";
		} else {
			cout<<(o&&z?"Yes\n":"No\n");	
		}	
	}	

}