#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		ll n,k,d;cin>>n>>k>>d;
		map<int,string>places;
		for(int i=1;i<=n;++i){
			string tmp;cin>>tmp;
			places[i]=tmp;
		}
		ll now=((d-1)*k)%n+1;
		pair<int,string>target[k];
		for(int i=now,j=0;j<k;i++,j++){
			if(i>n)i=i%n;
			target[j]={i,places[i]};
		}
		sort(target,target+k);
		cout<<"Case #"<<T++<<": ";
		for(auto i:target) cout<<i.second<<" ";
		cout<<"\n";  
	}
}