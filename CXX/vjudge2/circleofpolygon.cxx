#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	int n,s;
	cin>>n>>s;
	long double pi=3.141592653589;
	long double r=s/(2*sin((pi/n)));
	cout<<setprecision(9)<<fixed<<pi*r*r;
}

