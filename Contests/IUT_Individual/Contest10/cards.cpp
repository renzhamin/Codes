#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int a,b,c,x,y,z;
	while(cin>>a>>b>>c>>x>>y && (a+b+c+x+y)){
		int cards[53]{};
		int xg=(x>a&&x>b&&x>c);
		int yg=(y>a&&y>b&&y>c);
		int xt=(x>a&&x>b || x>b&&x>c || x>c&&x>a);
		int yt=(y>a&&y>b || y>b&&y>c || y>c&&y>a);
		if(!(xg+yg+xt+yt)) done(-1)
		cards[a]=1,cards[b]=1,cards[c]=1,cards[x]=1,cards[y]=1;
		if(xg && yg) {
			int i=1;
			while(cards[i]) i++;
			done(i);
		}
		if(xt+yt<2 && !(xg+yg)) done(-1);
		if(xt+yt==1) {
			if(xg+yg==1){
				int mW=max({a,b,c});
				if(cards[mW+1]==0 && mW+1<=52) done(mW+1);
				if(cards[mW+2]==0 && mW+2<=52) done(mW+2);
				if(cards[mW+3]==0 && mW+3<=52) done(mW+3);
				if(cards[mW+4]==0 && mW+4<=52) done(mW+4);
				if(cards[mW+5]==0 && mW+5<=52) done(mW+5);
			}
            done(-1)
		}
		int e[3];e[0]=a,e[1]=b,e[2]=c;
		sort(e,e+3);
		int mW=e[1];
		if(cards[mW+1]==0 && mW+1<=52) done(mW+1);
		if(cards[mW+2]==0 && mW+2<=52) done(mW+2);
		if(cards[mW+3]==0 && mW+3<=52) done(mW+3);
		if(cards[mW+4]==0 && mW+4<=52) done(mW+4);
		if(cards[mW+5]==0 && mW+5<=52) done(mW+5);		
		done(-1)
	}	
}