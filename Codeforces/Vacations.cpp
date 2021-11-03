#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int *a,n,mem[105][2][2];
int solve(int i,bool sport,bool contest){
	if(i>n) return 0;
	if(mem[i][sport][contest]!=-1)
		return mem[i][sport][contest];
	
	if(a[i]==1){
		if(contest)
			return mem[i][sport][contest]=1+solve(i+1,0,0);
		if(sport)
			return mem[i][sport][contest]=solve(i+1,0,1);
		return mem[i][sport][contest]=solve(i+1,0,1);
	} 
	
	if(a[i]==2){
		if(sport)
			return mem[i][sport][contest]=1+solve(i+1,0,0);
		if(contest)
			return mem[i][sport][contest]=solve(i+1,1,0);
		return mem[i][sport][contest]=solve(i+1,1,0);		
	} 
	
	if(a[i]==3){
		if(sport)
			return mem[i][sport][contest]=solve(i+1,0,1);
		 if(contest)
			return mem[i][sport][contest]=solve(i+1,1,0);
		return mem[i][sport][contest]=min(solve(i+1,1,0),solve(i+1,0,1));				
	} 
		
	return mem[i][sport][contest]=1+solve(i+1,0,0); //a[i]==0
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	memset(mem,-1,sizeof(mem));
	cin>>n;
	int arr[n+1]{};
	a=arr;
	for(int i=0;i<n;i++) cin>>arr[i+1];	
	cout<<solve(1,0,0)<<"\n";
}

/*
4
1 3 2 0

*/