#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

ld slope(ld x1,ld x2,ld y1,ld y2){
	ld dy=y2-y1,dx=x2-x1;
	if(!dx) return 1e6;
	return (dy/dx);
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ld n,x1,y1,x2,y2;
	cin>>n>>x1>>y1;
	set<ld>pos;
	while(n--){
		cin>>x2>>y2;
		pos.emplace(slope(x1,x2,y1,y2));
	}
	cout<<pos.size()<<"\n";
}