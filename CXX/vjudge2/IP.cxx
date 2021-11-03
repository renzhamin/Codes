#include <iostream>
#include <stdio.h>
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
	int t;cin>>t;
	for(int i=1;i<=t;i++){
	int d[4],bin[4];
	scanf("%d.%d.%d.%d",&d[0],&d[1],&d[2],&d[3]);
	scanf("%d.%d.%d.%d",&bin[0],&bin[1],&bin[2],&bin[3]);
	bool flag=1;
	int b[4]={b2d(bin[0]),b2d(bin[1]),b2d(bin[2]),b2d(bin[3])};
	if((d[0]!=b[0]) || (d[1]!=b[1]) || (d[2]!=b[2]) || (d[3]!=b[3]))
        flag=0;


	cout<<"Case "<<i<<": "<<(flag? "Yes":"No" )<<endl;
	}
}
