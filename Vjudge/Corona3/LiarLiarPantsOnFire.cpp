#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,lies;
	int t,T=1;cin>>t;
	while(t--){
		cin>>n;
		double arr[n+1];arr[0]=2;
		for(int i=0;i<n;i++) cin>>arr[i+1];
		lies=0;
		for(int i=1;i<=n;i++) lies+=(ceil((arr[i]-arr[i-1])/5));
		cout<<"Case "<<T++<<": ";
		cout<<lies<<"\n";
	}
}