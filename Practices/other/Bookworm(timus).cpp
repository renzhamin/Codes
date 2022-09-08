#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll v,c,a,b;
	cin>>v>>c>>a>>b;
	ll dif=abs(a-b);
	ll ans;
	if(a<b) ans=(dif-1)*v+(dif-1)*2*c+2;
	else ans=(dif+1)*v+(dif-1)*2*c+2;
	if(!a && !b) ans=0;
	cout<<ans<<"\n";
}