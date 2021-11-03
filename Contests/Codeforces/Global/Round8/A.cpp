#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		ll a,b,n,s=0;
		cin>>a>>b>>n;
		while(1){
			if(a>n || b>n) break;
			else s++;
			if(a>b)
				b+=a;
			else
				a+=b;
		}
		cout<<s<<"\n";
	}
}