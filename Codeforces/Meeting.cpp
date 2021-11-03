#include <bits/stdc++.h>
#define ll long long 
#define mx 1010
using namespace std;

struct radiators{
	ll x,y,r;
} a[mx];

ll n;

ll isInsideX(ll x,ll y,ll y2){
	ll s=0;
	bool y1d=1,y2d=1;
	for(int i=0;i<n && (y1d+y2d);++i){
		if(y1d && ((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)-a[i].r*a[i].r)<=0LL)
			s++,y1d=0;
		if(y2d && ((x-a[i].x)*(x-a[i].x)+(y2-a[i].y)*(y2-a[i].y)-a[i].r*a[i].r)<=0LL)
			s++,y2d=0;
	}
	return s;
}

ll isInsideY(ll x,ll x2,ll y){
	ll s=0;
	bool x1d=1,x2d=1;
	for(int i=0;i<n && (x1d+x2d);++i){
		if(x1d && ((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)-a[i].r*a[i].r)<=0LL)
			s++,x1d=0;
		if(x2d && ((x2-a[i].x)*(x2-a[i].x)+(y-a[i].y)*(y-a[i].y)-a[i].r*a[i].r)<=0LL)
			s++,x2d=0;
	}
	return s;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll x1,x2,y1,y2,xmin,xmax,ymin,ymax,xd,yd,s=0;
	cin>>x1>>y1>>x2>>y2>>n;
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y>>a[i].r;
	xmin=min(x1,x2),ymin=min(y1,y2);
	xmax=max(x1,x2),ymax=max(y1,y2);

	for(ll i=xmin;i<=xmax;++i){
		s+=isInsideX(i,ymax,ymin);
	}

	for(ll i=ymin+1;i<ymax;++i){
		s+=isInsideY(xmax,xmin,i);
	}
	cout<<(xmax-xmin)*2LL+(ymax-ymin)*2LL-s<<"\n";
}

