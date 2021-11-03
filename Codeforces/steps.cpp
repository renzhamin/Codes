#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,x,y,dx,dy,k,ans=0LL;

bool inbound(ll x,ll y,ll mid){
	x=x+dx*mid,y=y+dy*mid;
	return x>0 && x<=n && y>0 && y<=m;
}


void bs(){
	ll low=1,mid,high=1e9,s=0LL;
	while(low<=high){
		mid=(low+high)/2LL;
		if(inbound(x,y,mid))
			low=mid+1,s=mid;
		else
			high=mid-1;
	}
	x=x+dx*s,y=y+dy*s;
	ans+=s;
}



int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>n>>m>>x>>y>>k;
	while(k--){
		cin>>dx>>dy;
		bs();
	}	
	cout<<ans<<"\n";
}