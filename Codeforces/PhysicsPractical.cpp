#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];	
	sort(arr,arr+n);
	int b=0,e=n-1,s=0;
	while(e>b){
		int i=b,j=e;
		while(arr[i]*2<arr[e] && i<=e) i++;
		while(arr[b]*2<arr[j] && j>=b) j--;

		if(i-b<e-j) {s+=i-b,b=i,e--;cout<<arr[e+1]<<"\n";}
		else {s+=e-j,e=j,b++;cout<<arr[b-1]<<"\n";} 
	}

	cout<<s<<"\n";
}