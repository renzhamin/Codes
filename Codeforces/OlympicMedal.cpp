#include <bits/stdc++.h>
#define ll long long 
using namespace std;

double getr2(double r1,double p1,double p2,double A,double B){
	return r1*sqrt(B*p1/(B*p1+A*p2));
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	double A,B;
	int n;

	cin>>n;
	double R1[n];for(int i=0;i<n;i++) cin>>R1[i];	
	double r1=*max_element(R1,R1+n);
	
	cin>>n;
	double P1[n];for(int i=0;i<n;i++) cin>>P1[i];	

	cin>>n;
	double P2[n];for(int i=0;i<n;i++) cin>>P2[i];	
	double p2=*min_element(P2,P2+n);

	cin>>A>>B;

	double r2=-1;

	for(auto i:P1) r2=max(r2,getr2(r1,i,p2,A,B));
	cout<<setprecision(15)<<fixed<<r2<<"\n";
}