#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

const ll base=53,M=(ll)1e17+3;

ll id(char x){
	switch(x){
		case 'A': return 2;
		case 'B': return 3;
		case 'C': return 5;
	}
}

ll arr[(int)1e6];

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s,f="ABC"; cin>>s;
	int n=s.length(),ans=0;
	ll habc=0;
	if(n<3) done(0)
	if(n==3)if(s=="ABC") done(1) else done(0)
	ll powK=1;
	for(int i=1;i<=3;++i){
		habc=habc*base+id(f[i-1]);
		powK*=base;
	}

	for(int i=1;i<=n;++i){
		arr[i]=arr[i-1]*base+id(s[i-1]);
	}

	for(int i=3;i<=n;++i){
		ll hv=arr[i]-arr[i-3]*powK;
		if(hv==habc){
			// if(s.substr(i-3,3)!="ABC") continue;
			ans++;
			s[i-1]='A';
			arr[i]=arr[i]-id('C')+id('A');
			if(i+1<=n) arr[i+1]=arr[i]*base+id(s[i]);
			if(i+2<=n) arr[i+2]=arr[i+1]*base+id(s[i+1]);
			i++;
		}
	}
	cout<<ans<<"\n";
}