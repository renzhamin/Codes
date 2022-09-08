#include <bits/stdc++.h>
#define ll long long 
#define MX 100001
using namespace std;
ll h[MX];
bool good[MX];

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	memset(good,1,sizeof(good));
	int n,m,tmp1,tmp2,s=0;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>h[i+1];
	while(m--){
		cin>>tmp1>>tmp2;
        if(h[tmp1]>h[tmp2]){
        	good[tmp2]=0;
        }else if(h[tmp1]<h[tmp2]){
        	good[tmp1]=0;
        } else {
        	good[tmp1]=0;good[tmp2]=0;
        }
	}
	for(int i=1;i<=n;++i){
		s+=good[i];
	}
	cout<<s<<"\n";
}