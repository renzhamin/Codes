#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	set<ll>st;
	int n;cin>>n;
	ll arr[n+1];
	for(int i=0;i<n;i++) cin>>arr[i],st.emplace(arr[i]);	
	if(st.size()>3){
		cout<<"NO"<<"\n";
	} else {
		if(st.size()==1 || st.size()==2){
			cout<<"YES\n"<<"\n";
		} else {
			auto it=st.begin();it++;
			ll mid=*it;
			ll x1=mid-*st.begin();
			it++;
			ll x2=*it-mid;
			if((!x1 && !x2) || (x1==x2)){
				cout<<"YES"<<"\n";
			} else {
				cout<<"NO"<<"\n";
			}
		}
	}
}