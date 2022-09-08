#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	ll arr[n+1];
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;cin>>k;
	deque<pair<ll,int>>q;
	for(int i=0;i<k;++i){
		while(!q.empty() && arr[i]>=q.back().first) q.pop_back();
		q.push_back({arr[i],i});
	}
	cout<<q.front().first<<" ";
	for(int i=k;i<n;++i){
		while(!q.empty() && q.front().second<=i-k) q.pop_front();
		while(!q.empty() && arr[i]>=q.back().first) q.pop_back();
		q.push_back({arr[i],i});
		cout<<q.front().first<<" ";
	}
}