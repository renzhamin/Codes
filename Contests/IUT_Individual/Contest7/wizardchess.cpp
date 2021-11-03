#include <bits/stdc++.h>
#define ld long double
using namespace std;
pair<ld,int>p[100002];
double PI=3.141592653589793238462;

ld angle(ld x,ld y){
	ld d=abs(x-y);
	if(d>PI)
	d=2*PI-d;
	return d;
}
	
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	ld x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		p[i].first=atan2(y,x);
		p[i].second=i+1;
	}
	sort(p,p+n);
	int a=0,b=0;
	ld mn=PI,tmp;
	for(int i=1;i<n;i++){
	 	tmp=angle(p[i-1].first,p[i].first);
		// cout<<tmp<<endl;
		if(tmp<mn){
			a=p[i].second;
			b=p[i-1].second;
			mn=tmp;
		}
	}
	tmp=angle(p[0].first,p[n-1].first);
	if(tmp<mn){
		a=p[0].second;
		b=p[n-1].second;
		mn=tmp;
	}
	cout<<a<<" "<<b<<endl;
}
	