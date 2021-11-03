#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	if(a[0]+a[1]+a[2]==0 || a[0]+a[1]+a[2]==3) done("*")
	int cur=a[0];
	if(a[0]!=a[1] && a[0]!=a[2]) done('A')
	for(int i=1;i<3;i++) {
		if(a[i]!=cur) done((char)('A'+i))
		cur=a[i];
	}
}