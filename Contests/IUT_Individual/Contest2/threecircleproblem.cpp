#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double area(double a,double b,double c){
	double s=(a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

double x,y,z;
double sarea(double r){
	return (area(x+r,y+r,x+y)+area(x+r,z+r,x+z)+area(y+r,z+r,z+y)); 
}

double bs(double low,double high,double s){
	double mid;
	while(high-low>=1e-7){
		mid=(low+high)/2.0;
		if(sarea(mid)>s)
			high=mid;
		else
			low=mid;
	}
	return mid;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>x>>y>>z;
		double barea=area(x+y,y+z,z+x);
		cout<<setprecision(8)<<fixed<<bs(0.0,(x+y+z),barea)<<endl;
	}
}