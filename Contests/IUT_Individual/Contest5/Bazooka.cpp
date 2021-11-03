#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	double t,r,x,y,x1,x2,a,m,b,m1,m2,c,c1,c2;cin>>t;
	while(t--){
		cin>>a>>b>>r;
		if(a==r){
			cout<<setprecision(6)<<fixed<<a-r<<" "<<b<<endl;
			continue;
		}

		c=sqrt(a*a+b*b-r*r);
		c1=b*b-r*r,c2=a*a-r*r;
		//m=(-2*a*b+sqrt(4*(a*a*b*b-(b*b-4*c)*(a*a-4*c))))/(2*(b*b-4*c));
		
		m1=(2*a*b+sqrt((4*a*a*b*b-4*c1*c2)))/(2*c2);
		m2=(2*a*b-sqrt((4*a*a*b*b-4*c1*c2)))/(2*c2);
		m=m1;
		x1=(2*(a+b*m)+sqrt(4*((a+b*m)*(a+b*m))-c*(m*m+1)))/(2*(m*m+1));
		m=m2;
		x2=(2*(a+b*m)+sqrt(4*((a+b*m)*(a+b*m))-c*(m*m+1)))/(2*(m*m+1));
		if(x1<x2){
			x=x1;
			y=m1*x1;
		} else {
			x=x2;
			y=m2*x2;
		}

		cout<<setprecision(6)<<fixed<<x<<" "<<y<<endl;
	}
}