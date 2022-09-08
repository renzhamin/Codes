#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<int>arr;
int n,ans,maxnow;

int solve(int i,int p){
	if(i>=n) return 0;
	int ans1=0,ans2=0;
	ans1=solve(i+1,p);
	if(arr[i]<=arr[p])
		ans2=1+solve(i+1,i);
	maxnow=max(ans1,ans2);
	ans=max(ans,maxnow);
	return maxnow;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int num,num2,T=1;
	while(cin>>num){
		if(num==-1) {
			n=arr.size();ans=0;
			arr.emplace_back(40000);
			solve(0,n);
			cout<<"Test #"<<T++<<":\n  maximum possible interceptions: ";
			cout<<ans<<"\n";
			arr.clear();
			cin>>num2;
			if(num2==-1) break;
			cout<<"\n";
			arr.emplace_back(num2);
			continue;
		}
		arr.emplace_back(num);
	}
}