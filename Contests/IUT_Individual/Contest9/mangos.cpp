#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll o1,o2,o3,m1,m2,m3,ob,mb,om,mm;
	cin>>o1>>m1>>o2>>m2>>o3>>m3;
	mb=m2,ob=o3;
	om=o1-ob,mm=m1-mb;
	cout<<om<<" "<<mm<<"\n";	
}