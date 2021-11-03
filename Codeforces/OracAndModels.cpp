#include <bits/stdc++.h>
#define ll long long
#define MX 100001 
using namespace std;
ll n,arr[MX],cnt[MX],s,ans=0;

ll solve(int i,int pi){
	if(i>n)
		return 0;
	ll ans1=0,ans2=0;
	ans1=solve(i+1,i+1);
	if(i!=pi && arr[pi]<arr[i])
		ans2=1+solve(i+i,i)
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>arr[i];
		cout<<ans<<"\n";
	}	
}