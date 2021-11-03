#include <bits/stdc++.h>
#define ll long long 
using namespace std;


const int mx=(int)1e4;
int phi[mx+1];

void initphi(){
	phi[1]=1;
	for(ll i=2;i<=mx;++i){
		if(!phi[i]){
			phi[i]=i-1;
			for(ll j=2*i;j<=mx;j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}


int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	initphi();

	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll s=0,ans=0;
		for(int i=1;i<=n;i++) s+=phi[i];
		for(int i=1;i<=n;i++) ans+=(phi[i]*s);
		cout<<ans<<"\n";
	}
}