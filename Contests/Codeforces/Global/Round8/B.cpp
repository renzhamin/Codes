#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

int main(){
	ll p[41][11];
	for(int i=1;i<41;++i){
		for(int j=0;j<11;j++)
			p[i][j]=powl(i,j);
	}
	
	string a="codeforces";

	ld k;
	cin>>k;
	
	ld m=powl(k,1.0/10.0);
	ll mx=ceil(m);

	ll b1=mx-1,b2=mx;

	int i=10,j=0;
	ll s=p[b1][i]*p[b2][j];

	while(s<k){
		i--,j++;
		s=p[b1][i]*p[b2][j];
	}



	int q=0;
	for(;q<i;++q){
		for(int x=0;x<b1;x++)
			cout<<a[q]; 
	}


	for(;q<a.length();++q){
		for(int x=0;x<b2;x++)
			cout<<a[q]; 
	}



}