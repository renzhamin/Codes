#include <iostream>
#include <math.h>
using namespace std;
int b2d(int n){
	int r,s=0;
	for(int i=0;n>0;i++){
		r=n%10;
		n/=10;
		s+=r*pow(2,i);
	}
	return s;
}

int main(){
	int n;
	cin>>n;
	cout<<b2d(n);
}