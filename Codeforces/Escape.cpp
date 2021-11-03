#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	double vp,vd,t,tx,ty,c,f,sp,x;
	cin>>vp>>vd>>t>>f>>c;
	tx=(vp*t)/(vd-vp);
	sp=vp*(t+tx);
	if(sp>=c || tx<0) done(0)
	int s=1;	
	while(1){
		x=(f+(2*sp)/vd)*vp;
		ty=x/(vd-vp);
		sp+=x+ty*vp;
		if(sp>=c) done(s)
		s++;
	}
}