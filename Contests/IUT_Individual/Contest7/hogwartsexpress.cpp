#include <bits/stdc++.h>
#define ll long long 
#define pi 3.141592653589793238
using namespace std;

double angle(ll a,ll b){
	double x=abs(a),y=abs(b),p=180,ac=90,ts=360;
	double ans=atan(y/x)*(p/pi);
	
	if(a>=0 && b>=0)
		return ans;

	if(a<=0 && b<=0)
		return (p + ans);
	
	if(a<=0 && b>=0)
		return (p - ans);

	if(a>=0 && b<=0)
		return (-ans);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,x,y;cin>>n;
	pair<double,int>angles[n+1];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		angles[i]={angle(x,y),i};
	} 
	sort(angles,angles+n);
	// for(int i=0;i<n;i++) cout<<angles[i].first<<"\n"; 
	double dist=angles[n-1].first,tmp=dist;
	ll p1=1,p2=2;
	for(int i=0;i<n-1;i++){
		tmp=angles[i+1].first-angles[i].first;
		if(tmp<dist){
			p1=angles[i+1].second+1,p2=angles[i].second+1;
			dist=tmp;
		}
	} 
	cout<<p1<<" "<<p2<<"\n";
}