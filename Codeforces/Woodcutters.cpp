#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll x[(int)1e5+1],h[(int)1e5+1],n;
ll mem[(int)1e5+1];
ll cut(int i,ll left,ll right){
	if(i>=n) return 0;
	if(mem[i]!=-1) return mem[i];
	if(i==n-1)
		return 1;
	int ans1=0,ans2=0,ans3=0;
	if(x[i]-h[i]>right)
		ans1=1+cut(i+1,x[i]-h[i],x[i]);
	if(i+1<n){
		if(x[i]+h[i]<x[i+1])
			ans2=1+cut(i+1,x[i],x[i]+h[i]);
	} 
	ans3=cut(i+1,x[i],x[i]);
	return mem[i]=max({ans1,ans2,ans3});
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	memset(mem,-1,sizeof(mem));
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>h[i];	
	cout<<cut(1,x[0],x[0])+1<<"\n";
}