#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;

ll lqa(ll *arr,int n,ll value){
	ll i=lower_bound(arr,arr+n,value)-arr;
	if(i==0 && arr[i]>value) return -1;
	if(i==n) i--;
	if(arr[i]>value && i) i--;	
	return i;
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,m,t,k,x,y;
	string s[]={"Grapes","Carrots","Kiwis","Waste"};
	cin>>n>>m>>k>>t;
	ll arr[k];
	for(int i=0;i<k;i++) cin>>x>>y,arr[i]=m*(x-1)+y;
	sort(arr,arr+k);
	while(t--){
		cin>>x>>y;
		ll pos=m*(x-1)+y;
		ll ind=lqa(arr,k,pos);
		if(ind==-1)
			done(s[pos%3])
		if(arr[ind]==pos)
			done(s[3])
		pos=pos-ind-1;
		done(s[pos%3])
	}
}