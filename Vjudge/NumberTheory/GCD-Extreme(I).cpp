#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e3;
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


ll sum[mx+1];
void gcdsum(){
	for(int i=1;i<=mx;i++){
		for(int j=i*2;j<=mx;j+=i){
			sum[j]+=i*phi[j/i];
		}
	}

	for(int i=2;i<=mx;i++) sum[i]+=sum[i-1]; 
}


int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	initphi();
	gcdsum();
	ll n;
	while(cin>>n && n){
		cout<<sum[n]<<"\n";
	}

}