#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n;cin>>n;
	pair<ll,ll>a[n];
	for(int i=0;i<n;i++) cin>>a[i].first,a[i].second=i;
	if(n==1) done("1\n"<<a[0].first<<" "<<0)
	sort(a,a+n);
	bool f=1,ft=1,ao=0;
	ll dif=0,pdif=0,s=0;
	vector<pair<ll,ll>>ans;
	for(int i=1;i<n;++i){
		if(a[i].first!=a[i-1].first){
			if(f) ans.emplace_back(a[i-1].first,pdif),s++;
			f=1; pdif=0; ft=1;
		} else {
			dif=a[i].second-a[i-1].second;
			if(dif!=pdif && !ft) f=0;
			pdif=dif;
			ft=0;
			ao=1; 
		}
	}
	if(f)ans.emplace_back(a[n-1].first,pdif),s++;
	cout<<s<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n"; 
}