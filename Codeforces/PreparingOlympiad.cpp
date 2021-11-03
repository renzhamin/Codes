#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n,l,r,x;
int a[15],s=0;

void sub(vector<int>arr={},int i=0,int sum=0,int t=0){
	if(i==n){
		if(sum>=l && sum<=r && t>=2){
			sort(arr.begin(),arr.end());
			if(arr[arr.size()-1]-arr[0]>=x)
				s++;		
		}
		return;
	}
	
	sub(arr,i+1,sum,t);
	arr.push_back(a[i]);
	sub(arr,i+1,sum+a[i],t+1);
	arr.pop_back();
}


int main(){
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;i++) cin>>a[i];
	sub();
	cout<<s<<"\n";
}