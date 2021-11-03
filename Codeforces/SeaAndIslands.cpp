#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;
int main(){
	int n,k,mx;
	cin>>n>>k;
	if(n&1)
		mx=(n/2)*(n/2)+ceil((double)n/2)*ceil((double)n/2);
	else 
		mx=n*n/2;

	
	if(k>mx) done("NO")

	cout<<"YES"<<"\n";
	for(int i=0;i<n;i++,cout<<"\n"){
		for(int j=0;j<n;j++){
			if(k){
				if((i+j)&1)
					cout<<"S";
				else
					cout<<"L",k--;				
			} else
				cout<<"S";
		}
	}
}