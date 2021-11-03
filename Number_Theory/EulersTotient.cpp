#include <bits/stdc++.h>
#define ll long long 
using namespace std;


ll calcphi(ll n){
	ll val=sqrt(n)+1,s=n;
	for(ll i=2;i<val;++i){
		if(n%i==0){
			s*=(i-1),s/=i;
			while(n%i==0) n/=i;
		}
	}

	if(n>1) s*=(n-1),s/=n;

	return s;
}



	
int main(){

	ll n;
	while(cin>>n) cout<<calcphi(n)<<"\n";
}





const int mx=(int)1e6;
int phi[mx+1];

void initphi(){
	phi[1]=1;
	for(ll i=2;i<=mx;++i){
		if(!phi[i]){
			phi[i]=i-1;
			for(ll j=2*i;j<=mx;j+=i){
				if(!phi[j]) phi[j]=j;
				// phi[j]*=(i-1),phi[j]/=i;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
