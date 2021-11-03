#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,cur,pos;
	cin>>n>>cur;
	int arr[n];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int ans=0;
	for(int i=1;i<=cur;++i){
		int city1=cur-i,
			city2=cur+city1;
		if(arr[i]){
			if(city2>n)
				ans+=1;
			else
			if(arr[city2]==1)
				ans+=2;
		}
	}
	if(arr[cur]) ans--;
	cur*=2;
	while(cur<=n) ans+=arr[cur],cur++;	
	cout<<ans<<"\n";    
}