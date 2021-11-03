#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int sx[35],sy[35],d[100];
bool have[200];

ll dist(ll Sy,ll Sx,ll i,ll j){
	ll x=(Sx-j),y=(Sy-i);
	double s=sqrt(x*x+y*y);
	ll ans=ceil(s);
	return ans;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	memset(d,-1,sizeof(d));
	ll n,m,x;cin>>n>>m>>x;
	string s[n]; bool shift=0;
	for(int i=0;i<n;i++) cin>>s[i];
	int sh=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				sx[sh]=j+1;
				sy[sh++]=i+1;
				shift=1; 
			} else {
				have[s[i][j]-'a']=1;
			}				
		}
	}
	for(int i=0;i<sh;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<m;++k){
				ll ds=dist(sy[i],sx[i],j+1,k+1);
				if(ds>x){
					if(d[s[j][k]-'a']==-1)
						d[s[j][k]-'a']=1;
				}
				else
					d[s[j][k]-'a']=0;
			}
		}
	}


	cin>>n;
	string t; cin>>t;
	ll ans=0,id;
	for(int i=0;i<n;++i){
		if(isupper(t[i])){	
			if(!shift) done(-1)
			t[i]=t[i]+32;
			id=t[i]-'a';
			if(!have[id]) done(-1)
			ans+=d[id];
		} 
		if(!have[t[i]-'a'])
			done(-1)
	} 
	done(ans)
}