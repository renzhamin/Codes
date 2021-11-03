#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,m,a,b,D;
	cin>>n>>m;
	ll arr[n+1]{};
	while(m--){
		cin>>a>>b>>D;
		arr[a]-=D,arr[b]+=D;
	}
	ll s=0;
	for(int i=1;i<=n;i++) s+=arr[i]>0?arr[i]:0;
	cout<<s<<"\n"; 
}