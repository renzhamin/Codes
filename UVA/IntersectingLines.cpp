#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

void coeff(ld x1,ld y1,ld x2,ld y2,ld &a,ld &b,ld &c){
	a = y1-y2;
	b = x2-x1;
	c = x1*y2 - x2*y1;
}

void intersect(ld a1,ld b1,ld c1,ld a2,ld b2,ld c2,ld &x,ld &y,ld &c){
	c = a1*b2 - a2*b1;
	x = (b1*c2-c1*b2);
	y = (a2*c1-a1*c2);
}

int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	ld x1,y1,x2,y2,x3,y3,x4,y4;
	
	cout<<"INTERSECTING LINES OUTPUT"<<"\n";
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		
		ld x,y,a1,b1,c1,a2,b2,c2,c;
		coeff(x1,y1,x2,y2,a1,b1,c1);
		coeff(x3,y3,x4,y4,a2,b2,c2);
		intersect(a1,b1,c1,a2,b2,c2,x,y,c);
		
		if(!c && !x && !y) 
			cout<<"LINE"<<"\n";
		else if(!c && (x || y))
			cout<<"NONE"<<"\n";
		else
			cout<<"POINT "<<setprecision(2)<<fixed<<x/c<<" "<<y/c<<"\n";
	}
	
	cout<<"END OF OUTPUT"<<"\n";
}