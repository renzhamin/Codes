#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll M=(ll)1e17+3,M2=(ll)1e13+7,base=29,base2=27;

void compute(ll *arr,ll *arr2,string &s){
	arr[0]=arr2[0]=s[0]-'a';
	int n=s.length();
	for(int i=1;i<n;++i){
		arr[i]=((arr[i-1]*base)%M+s[i]-'a')%M;
		arr2[i]=((arr2[i-1]*base2)%M2+s[i]-'a')%M2;
	}
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);		
	int t;cin>>t;
	while(t--){
		ll n,k;string s;cin>>n>>k>>s;
		ll arr[n+1],arr2[n+1]; 
		compute(arr,arr2,s);
		unordered_set<ll>mp,mp2;
		ll powB=1,powB2=1;
		for(int i=0;i<k;i++) {
			powB*=base%M;
			powB2*=base2%M2;
		}
		mp.insert(arr[k-1]);
		mp2.insert(arr2[k-1]);
		ll ans=1;
		for(int i=k;i<n;++i){
			ll hv=(arr[i]-(arr[i-k]*powB)%M+M)%M;
			ll hv2=(arr2[i]-(arr2[i-k]*powB2)%M2+M2)%M2;
			if(mp.find(hv)==mp.end() && mp2.find(hv2)==mp2.end())
				ans++;
			mp.insert(hv);
			mp2.insert(hv2);
		}
		cout<<ans<<"\n";
	}
}