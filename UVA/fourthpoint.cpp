#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	double x1,x2,x3,y1,y2,y3;
	while(cin>>x1>>y1>>x2>>y2>>x2>>y2>>x3>>y3)
		cout<<setprecision(3)<<fixed
		<<x1+x3-x2<<" "<<y1+y3-y2<<"\n";
}