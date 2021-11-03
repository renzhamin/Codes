#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";continue;} 
using namespace std;

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int minc=1,maxc=1,worst=-1,best=n+1,pbest=n+1;
		bool f=0,ab=0;
		
		if(arr[1]-arr[0]>2) best=1,ab=1;
		if(n==2){if(arr[1]-arr[0]<=2) done("2 2") else done ("1 1")}
		for(int i=0;i<n-1;++i){
			int d=arr[i+1]-arr[i];
			if(d>2){
				pbest=minc;
				minc=maxc=1;
				if(i!=n-2) {if(arr[i+2]-arr[i+1]>2) best=1; f=1;}
				else best=1;
			} else {
				minc++,maxc++;
				best=min(minc,pbest);
				worst=max(worst,maxc);
			}
		}
		if(worst==-1) worst=1;
		if(ab) best=1;
		cout<<best<<" "<<worst<<"\n";
	}
	
}