#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		ll n; cin>>n;
		ll arr[n+1],ans=1;
		for(int i=0;i<n;i++) cin>>arr[i+1];
		sort(arr+1,arr+n+1);
		for(int i=1;i<=n;++i){
			if(i>=arr[i])	
				ans=i+1;	
		}
		cout<<ans<<"\n";		
	}	
}