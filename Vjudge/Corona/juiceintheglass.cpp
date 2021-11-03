#include <iostream>
#include <iomanip>
#define M_PI 3.141592653589793238
using namespace std;


double findv(double r1,double r2,double h,double p){
	double x=h*r2/(r1-r2);
	double r=r2+(p*(r1-r2))/h;
	return double((M_PI*r*r)*(p+x)/3-(M_PI*r2*r2*x)/3);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int T,t=0;cin>>T;
	double r1,r2,h,p;
	while(T--){
		cin>>r1>>r2>>h>>p;
		cout<<"Case "<<++t<<": ";
		cout<<setprecision(9)<<fixed<<findv(r1,r2,h,p)<<endl;
	}
}