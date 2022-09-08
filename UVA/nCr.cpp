#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll mem[102][102];

ll nCr(ll n,ll r){
	if(mem[n][r]!=0)
		return mem[n][r];
	if(n==r || r==0) 
		return mem[n][r]=1;
	if(n-r==1 || r==1)
		return mem[n][r]=n;

	return mem[n][r]=nCr(n-1,r-1)+nCr(n-1,r); 
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,r;
	while(cin>>n>>r && n){
		cout<<n<<" things taken "<<r<<
		" at a time is " <<nCr(n,r)<<" exactly.\n";
	}
}
/*
100 6
20 5
18 6
5 4
2 0
0 0
*/