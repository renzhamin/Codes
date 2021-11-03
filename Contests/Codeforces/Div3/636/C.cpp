#include <bits/stdc++.h>
#define mx 10000000000
#define ll long long 
using namespace std;

ll n,cur,sum;

void skipP(ll *arr,int &i){
	while(i<n && arr[i]>0) cur=max(cur,arr[i]),i++;
}

void skipM(ll *arr,int &i){
	while(i<n && arr[i]<0) cur=max(cur,arr[i]),i++;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		bool plus=arr[0]>0;
		cur=-mx,sum=0;
		for(int i=0;i<n;plus^=1,sum+=cur,cur=-mx)
			plus?skipP(arr,i):skipM(arr,i);
		
		cout<<sum<<"\n";		
	}
}