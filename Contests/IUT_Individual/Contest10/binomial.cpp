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
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		string s;cin>>s;
		string a,b,c;
		string sp;
		size_t fa=s.find('+');
		a=s.substr(1,fa-1);
		size_t fb=s.find(')',fa+1);
		size_t pow=fb+1;
		b=s.substr(fa+1,fb-fa-1);
		sp=s.substr(pow+1,s.length()-pow);
		ll p=stoi(sp);
	    ll pa=p,pb=0,n=p;
	    
	    cout<<"Case "<<T++<<": ";
	    for(ll i=0;i<p+1;++i,pa--,pb++){
       	  ll x=nCr(n,i);
          if(x>1)
          	cout<<x<<"*";

		   if(pa>1){
		   	  cout<<a<<"^"<<pa;
		   } else if(pa==1){
		   	  cout<<a;
		   }
		   if(pa && pb) cout<<"*";
		   if(pb>1){
		   	  cout<<b<<"^"<<pb;
		   } else if(pb==1){
		   	  cout<<b;
		   }
		   if(i!=p) cout<<"+";
	    }
	    
	    
	    	cout<<"\n";
	}
}