#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int Z[10000],t[1001];

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int p,q,l,r,s=0;
	cin>>p>>q>>l>>r;
	while(p--){
		int s,e;cin>>s>>e;
		for(int i=s;i<=e;i++) Z[i]=1; 
	}
	pair<int,int>X[q];
	for(int i=0;i<q;i++) cin>>X[i].first>>X[i].second;
	for(int i=l;i<=r;++i){
		for(auto j:X){
			int start=i+j.first,end=i+j.second;
			for(int k=start;k	<=end;++k){
				if(Z[k]){
					t[i]=1;
					goto done;
				}
			}
		}
		done : ;  	
	}
	for(auto i:t) s+=i;
	cout<<s<<"\n";
}