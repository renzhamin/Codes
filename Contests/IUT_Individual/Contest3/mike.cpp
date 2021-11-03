#include <iostream>
#include <cstdio>
#define sc(a) scanf("%d",&a)
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;sc(t);
	while(t--){
		int x1=-1e5,x2=1e5,y1=-1e5,y2=1e5,xx1,yy1,xx2,yy2;
		int n; sc(n);
		bool zero=0;
		while(n--){
			scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
			if(zero) continue;
			x1=max(x1,xx1);
			x2=min(x2,xx2);
			y1=max(y1,yy1);
			y2=min(y2,yy2);
			if(xx2<x1 || xx1>x2 || yy2<y1 || yy1>y2) zero=1;
		}
		int ans;
		if(zero)
			ans=0;
		else
			ans=(x2-x1)*(y2-y1);
		printf("Case %d: %d",T++,ans);
	}
}